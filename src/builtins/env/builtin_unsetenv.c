/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** builtin_unsetenv
*/

#include "sh.h"

static int free_variable(sh_t *sh, char *key)
{
    link_t *actual = sh->env;
    my_env_t *variable = NULL;

    if (!actual || !key)
        return (1);
    do {
        variable = (my_env_t *) actual->obj;
        actual = actual->next;
        if (my_strcmp(variable->key, key) != 0)
            continue;
        list_remove(&(sh->env), actual->prev);
        free(variable);
        return (0);
    } while (sh->env && actual != sh->env);
    return (1);
}

int builtin_unsetenv(char **tab, sh_t *sh)
{
    int len = (int) my_two_len(tab);

    if (!sh->env || !tab)
        return (1);
    if (len == 1) {
        printf("unsetenv: Too few arguments.\n");
        return (1);
    } else if (len >= 2) {
        tab++;
        return free_variable(sh, *tab);
    }
    return (1);
}
