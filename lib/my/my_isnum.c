/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** my_isnum
*/

#include "my.h"

bool my_isnum(const char *str)
{
    if (!str)
        return false;
    if (str[0] == '-')
        str++;
    for (size_t i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return false;
    return true;
}
