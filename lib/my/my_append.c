/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** append a character to the end of a string
*/

#include "my.h"

char *my_append(char const *str, char c)
{
    size_t nbr = my_strlen(str);
    char *dest = calloc((nbr + 2), sizeof(char));

    if (!dest || !str)
        return (NULL);

    dest = my_strncopy(str, dest, nbr);
    dest[nbr] = c;
    dest[nbr + 1] = '\0';
    return dest;
}
