/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** handling_builtin
*/

#include "sh.h"

static const builtins_t builtins[] = {
    {"cd", &builtin_cd},
    {"setenv", &builtin_setenv},
    {"unsetenv", &builtin_unsetenv},
    {"env", &builtin_env},
    {"me", &check_mans},
    {"history", &print_history},
    {"alias", &manage_alias},
    {"meme", &builtin_meme},
    {"set", &manage_var},
    {"prompt", &personalize_prompt},
    {NULL, NULL}
};

bool check_builtins(chunk_t *chunk, sh_t *sh)
{
    for (size_t i = 0; builtins[i].flag; i++) {
        if (my_strcmp(chunk->arg[0], builtins[i].flag) == 0 && !chunk->fork) {
            sh->status = builtins[i].redirect(chunk->arg, sh);
            return true;
        }
    }
    return false;
}

bool is_builtin_can_fork(chunk_t *chunk, sh_t *sh)
{
    for (size_t i = 0; builtins[i].flag; i++)
        if (my_strcmp(chunk->arg[0], builtins[i].flag) == 0 && chunk->fork) {
            builtins[i].redirect(chunk->arg, sh);
            return true;
        }
    return false;
}
