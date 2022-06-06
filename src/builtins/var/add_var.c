/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** add_var
*/

#include "sh.h"

static var_t *create_var(char **argv)
{
    var_t *variable = malloc(sizeof(var_t));
    char **tmp = my_str_word_array(argv[1], '=');

    if (!tmp || !variable)
        return (NULL);
    variable->key = my_strdup(tmp[0]);
    variable->value = my_strdup(tmp[1]);
    my_two_free(tmp);
    return variable;
}

int add_var(char **argv, sh_t *sh)
{
    var_t *var = create_var(argv);
    link_t *link = create_link(var);

    if (!link)
        return (1);
    list_append(&(sh->var), link);
    return (0);
}
