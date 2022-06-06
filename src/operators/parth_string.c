/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** handling_error
*/

#include "sh.h"

void parth_string(sh_t *sh, char *str)
{
    char *tmp = my_strndup(str, strlen(str) - 1);
    char *end = NULL;

    if (!*str || !*tmp)
        return;
    tmp = check_two_reminder(tmp);
    tmp = check_reminder(tmp);
    tmp = check_var(tmp, sh);
    tmp = check_alias(tmp);
    add_to_history(tmp);
    end = my_clean_string(tmp);
    add_tree(end, sh);
    if (!*end || !*tmp)
        return;
    sh->status = 0;
    check_operators(end, sh);
    free(tmp);
    free(end);
}
