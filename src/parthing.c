/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** parthing
*/

#include "sh.h"

my_env_t *find_env_var(sh_t *sh, char *var)
{
    link_t *actual = sh->env;
    my_env_t *variable = NULL;

    if (!actual || !var)
        return (NULL);
    do {
        variable = (my_env_t *) actual->obj;
        if (my_strcmp(variable->key, var) == 0)
            return variable;
        actual = actual->next;
    } while (sh->env && actual != sh->env);
    return (NULL);
}

char *verif_path(char *str, sh_t *sh)
{
    my_env_t *path = find_env_var(sh, "PATH");
    char **tab = NULL;
    static char *tmp1 = NULL;
    static char *tmp2 = NULL;

    if (!path || !path->value)
        return str;
    tab = my_str_to_word_array(path->value, ":");
    if (!tab || !str || str[0] == '/')
        return str;
    for (size_t i = 0; tab[i]; i++) {
        tmp1 = my_strcat(str, "/");
        tmp2 = my_strcat(tmp1, tab[i]);
        if (access(tmp2, F_OK) == 0) {
            return tmp2;
        }
    }
    return str;
}
