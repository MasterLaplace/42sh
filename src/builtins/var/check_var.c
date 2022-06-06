/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** handling_var
*/

#include "sh.h"

static char *
rebuilt(const char *command, char *old_command, size_t len1, size_t len2)
{
    size_t len = len1 + len2 + strlen(old_command);
    size_t i = 0;
    size_t x = 0;
    size_t e = 0;
    char *new = calloc(len, sizeof(char));

    for (; i < len1 && command[i]; i++)
        new[i] = command[i];
    for (; old_command[x]; i++, x++)
        new[i] = old_command[x];
    for (e = len2; e < len2 && command[e]; i++, e++)
        new[i] = command[e];
    new[i] = '\0';
    return new;
}

static bool is_var(char **dest, char *str, var_t *var)
{
    for (size_t i = 0; str[i]; i++) {
        for (; str[i] != '$' && str[i]; i++);
        if (str[i] == '$'
            && my_strncmp(&str[i + 1], var->key, strlen(var->key)) == 0) {
            *dest = rebuilt(str, var->value, i,
                            strlen(&str[strlen(var->key) + 1]));
            return true;
        }
    }
    return false;
}

static char *verif_var(char *str, sh_t *sh)
{
    link_t *actual = sh->var;
    var_t *var = NULL;
    char *tmp = NULL;

    if (!actual)
        return my_strdup(str);
    do {
        var = (var_t *) actual->obj;
        if (is_var(&tmp, str, var))
            return tmp;
        actual = actual->next;
    } while (sh->var && actual != sh->var);
    return my_strdup(str);
}

char *check_var(char *command, sh_t *sh)
{
    char *new_command = NULL;

    if ((new_command = verif_var(command, sh))) {
        free(command);
        return new_command;
    }
    return command;
}
