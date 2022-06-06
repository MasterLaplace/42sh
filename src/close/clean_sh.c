/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** clean_sh
*/

#include "sh.h"

void clean_env(sh_t *sh)
{
    link_t *actual = sh->env;
    my_env_t *variable = NULL;

    if (!actual)
        return;
    do {
        variable = (my_env_t *) actual->obj;
        if (variable->key)
            free(variable->key);
        if (variable->value)
            free(variable->value);
        free(variable);
        actual = actual->next;
    } while (sh->env && actual != sh->env);
}

void clean_chunk(sh_t *sh)
{
    link_t *actual = sh->chunks;
    chunk_t *chunk = NULL;

    if (!actual)
        return;
    do {
        chunk = (chunk_t *) actual->obj;
        free(chunk);
        actual = actual->next;
    } while (sh->chunks && actual != sh->chunks);
}
