/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** free_env
*/

#include "sh.h"

void free_env(sh_t *sh)
{
    if (!sh->env)
        return;
    while (sh->env)
        list_remove(&(sh->env), sh->env);
}

void free_chunk(sh_t *sh)
{
    if (!sh->chunks)
        return;
    clean_chunk(sh);
    while (sh->chunks)
        list_remove(&(sh->chunks), sh->chunks);
}

void free_sh(sh_t *sh)
{
    free_env(sh);
    free_chunk(sh);
    free_style(sh);
}
