/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** handling_operator
*/

#include "sh.h"

static const char *flags[] = {
    ";",
    "&&",
    "||",
    ">>",
    "<<",
    ">",
    "<",
    "|",
    NULL
};

const check_fork_t handle_builtins[] = {
    {"cd", false, false},
    {"setenv", true, true},
    {"unsetenv", false, false},
    {"env", true, false},
    {"exit", false, false},
    {"me", true, false},
    {"history", true, false},
    {"alias", true, true},
    {"meme", true, false},
    {"set", true, true},
    {"prompt", false, false},
    {NULL, false, false}
};

static bool check_can_fork(chunk_t *chunk)
{
    size_t i = 0;

    for (; handle_builtins[i].av; i++)
        if (strcmp(chunk->arg[0], handle_builtins[i].av) == 0)
            break;
    if (handle_builtins[i].can_fork) {
        if (handle_builtins[i].with_arg && my_two_len(chunk->arg) == 1)
            return true;
        if (!handle_builtins[i].with_arg && my_two_len(chunk->arg) >= 1)
            return true;
    }
    if (!handle_builtins[i].av)
        return true;
    return false;
}

static chunk_t *create_chunk(char *str, size_t flag, size_t len)
{
    chunk_t *chunk = malloc(sizeof(chunk_t));
    char *tmp = my_strndup(str, len);

    if (!chunk || !*tmp)
        return (NULL);
    chunk->arg = my_str_word_array(my_clean_string(tmp), ' ');
    chunk->operator = flag;
    chunk->fork = check_can_fork(chunk);
    free(tmp);
    return chunk;
}

static size_t is_operators(char *str, size_t ind, sh_t *sh)
{
    size_t len = 0;

    for (size_t i = 0; flags[i]; i++) {
        len = my_strlen(flags[i]);
        if (my_strncmp(&str[ind], flags[i], len) == 0) {
            chunk_t *chunk = create_chunk(str, i, ind);
            link_t *link = create_link(chunk);
            list_append(&(sh->chunks), link);
            return len;
        }
    }
    return (0);
}

void check_operators(char *buf, sh_t *sh)
{
    char *tmp = my_strdup(buf);
    int len = my_strlen(tmp);
    size_t new_len = 0;

    if (!tmp || !buf)
        return;
    for (int i = 0; i <= len; i++) {
        if (!tmp[i]) {
            chunk_t *chunk = create_chunk(tmp, END, len);
            link_t *link = create_link(chunk);
            list_append(&(sh->chunks), link);
        }
        if ((new_len = is_operators(tmp, i, sh)) >= 1) {
            tmp = my_suppr(tmp, i + new_len);
            len = my_strlen(tmp);
            i = -1;
        }
    }
}
