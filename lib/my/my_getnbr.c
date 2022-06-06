/*
** EPITECH PROJECT, 2022
** B-CPE-210-REN-2-1-solostumper04-guillaume.papineau
** File description:
** change a string to a number
*/

#include "my.h"

static bool is_negative(char const *str)
{
    if (*str == '-')
        return true;
    return false;
}

int my_getnbr(char const *str)
{
    int exp = 0;

    if (!str)
        return exp;

    for (size_t i = is_negative(str); str[i] >= '0' && str[i] <= '9'; i++)
        exp = exp * 10 + str[i] - '0';
    if (is_negative(str))
        exp *= -1;
    return exp;
}
