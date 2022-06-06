/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** handling_alias
*/

#include "sh.h"

static char *
rebuilt(const char *command, char **old_command, size_t len1, size_t len2)
{
    size_t len = len1 + len2 + strlen(old_command[1]);
    size_t i = 0;
    size_t x = 0;
    size_t e = 0;
    size_t len_c = strlen(command);
    char *new = calloc(len, sizeof(char));

    for (; i < len1 && command[i]; i++)
        new[i] = command[i];
    for (; old_command[1][x]; i++, x++)
        new[i] = old_command[1][x];
    for (e = len_c - len2; e < len_c + len2 && command[e]; i++, e++)
        new[i] = command[e];
    new[i] = '\0';
    return new;
}

static char *replace(char *command, char *old_command)
{
    size_t i = 0;
    char **tmp = NULL;
    char *dest = NULL;

    if (!*old_command)
        return strdup(command);
    tmp = my_str_to_word_array(old_command, "=");
    for (; command[i]; i++) {
        if (strncmp(&command[i], *tmp, strlen(*tmp)) == 0)
            break;
    }
    dest = rebuilt(command, tmp, i, strlen(&command[i + strlen(tmp[0])]));
    my_two_free(tmp);
    return dest;
}

static int search_in_command(char *command, char **history)
{
    for (int i = 0; history[i]; i++) {
        if  (norm(history[i], command))
            return i;
    }
    return (-1);
}

char **load_alias(void)
{
    const char *pathname = ".cache/.alias";
    int fd = open(pathname, O_CREAT | O_RDWR | O_APPEND, S_IRUSR);
    struct stat st;
    char *buf = NULL;
    char **tab = NULL;

    stat(pathname, &st);
    if (st.st_size == 0)
        return NULL;
    buf = calloc(st.st_size + 1, sizeof(char));
    if (fd == -1 || !buf)
        return NULL;
    read(fd, buf, st.st_size);
    buf[st.st_size] = '\0';
    tab = my_str_to_word_array(buf, "\n");
    free(buf);
    close(fd);
    return tab;
}

char *check_alias(char *command)
{
    char **alias = load_alias();
    char *new_command = NULL;
    int nbr = 0;

    if (!alias)
        return command;
    nbr = search_in_command(command, alias);
    if (nbr != -1) {
        new_command = replace(command, alias[nbr]);
        free(command);
        my_two_free(alias);
        return new_command;
    }
    my_two_free(alias);
    return command;
}
