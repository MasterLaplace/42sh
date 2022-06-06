/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** builtin_setenv
*/

#include "sh.h"

static int update_key(sh_t *sh, char *key, char *value)
{
    link_t *actual = sh->env;
    my_env_t *variable = NULL;

    if (!actual || !key || !value)
        return (1);
    do {
        variable = (my_env_t *) actual->obj;
        actual = actual->next;
        if (my_strcmp(variable->key, key) != 0)
            continue;
        if (variable->value[0])
            free(variable->value);
        variable->value = my_strdup(value);
        return (0);
    } while (sh->env && actual != sh->env);
    return (1);
}

static int
set_variable(char *const *args, sh_t *sh, char *value, my_env_t *variable)
{
    if (!variable) {
        variable = malloc(sizeof(my_env_t));
        if (!variable)
            return (1);
        variable->key = args[1];
        variable->value = value;
        link_t *link = create_link(variable);
        list_append(&(sh->env), link);
    } else
        return update_key(sh, args[1], value);
    return (0);
}

static bool correct_key(char *key)
{
    if (key[0] >= '0' && key[0] <= '9' && key[0] != '_') {
        printf("setenv: Variable name must begin with a letter.\n");
        return false;
    } else if (my_isnumalpha(key) == 0) {
        printf("setenv: Variable name must contain ");
        printf("alphanumeric characters.\n");
        return false;
    } else
        return true;
}

int builtin_setenv(char **args, sh_t *sh)
{
    char *value = strdup("");
    int len = (int) my_two_len(args);
    my_env_t *variable = NULL;

    if (len == 1) {
        builtin_env(NULL, sh);
        return (1);
    } else if (len > 3) {
        printf("setenv: Too many arguments.\n");
        return (1);
    }
    if (correct_key(args[1]) == false)
        return (1);
    variable = find_env_var(sh, args[1]);
    if (len > 2)
        value = args[2];
    return set_variable(args, sh, value, variable);
}
