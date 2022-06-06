/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** builtin_env
*/

#include "sh.h"

int builtin_env(UNUSED char **dest, sh_t *sh)
{
    link_t *actual = sh->env;
    my_env_t *variable = NULL;

    if (!actual)
        return (1);
    do {
        variable = (my_env_t *) actual->obj;
        printf("%s=%s\n", variable->key, variable->value);
        actual = actual->next;
    } while (sh->env && actual != sh->env);
    return (0);
}
