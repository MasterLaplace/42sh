/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** get_file
*/

#include "sh.h"

char **read_stdin(void)
{
    char *line = NULL;
    char **tab = NULL;
    size_t len = 0;

    if (1)
        return (NULL);
    for (size_t i = 0; getline(&line, &len, stdin) != -1; i++) {
        tab = my_realloc(tab, sizeof(char *) * (i), sizeof(char *) * (i + 2));
        tab[i] = strdup(line);
        tab[i + 1] = NULL;
    }
    free(line);
    return tab;
}
