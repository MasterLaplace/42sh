/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** builtin_var
*/

#include "sh.h"

static int print_var(sh_t *sh)
{
    link_t *actual = sh->var;
    var_t *var = NULL;

    if (!actual)
        return (1);
    do {
        var = (var_t *) actual->obj;
        printf("%s  =  %s\n", var->key, var->value);
        actual = actual->next;
    } while (sh->var && actual != sh->var);
    return (0);
}

int manage_var(char **argv, sh_t *sh)
{
    if (my_two_len(argv) >= 2)
        return add_var(argv, sh);
    else
        return print_var(sh);
}
