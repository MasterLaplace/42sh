/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** my_strupcase
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    if (!str)
        return (NULL);

    for (size_t i = 0; str[i]; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 'a' - 'A';
    return str;
}
