/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** handle_script
*/

#include "sh.h"

static bool is_echo(char *str)
{
    for (; *str; str++)
        if (strncmp(str, "echo ", strlen("echo ")) == 0)
            return true;
    return false;
}

static void take_string(char *str)
{
    char *tmp = NULL;

    for (; *str && *str != '"'; str++);
    if (*str != '"')
        return;
    str++;
    tmp = strndup(str, my_char_in_list('"', str));
    printf("%s\n", tmp);
    free(tmp);
}

bool exec_script(sh_t *sh)
{
    if (!sh->script)
        return false;
    for (size_t i = 0; sh->script[i]; i++) {
        if (is_echo(sh->script[i])) {
            take_string(sh->script[i]);
            return true;
        }
    }
    return false;
}
