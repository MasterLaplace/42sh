/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** str to word array
*/
#include <stdlib.h>
#include <stddef.h>

static int my_char_is_alpha(char c)
{
    if (c >= 33 && c <= 126 && c != 124)
        return (1);
    return (0);
}

static int my_count_words(char const *str)
{
    int i = 0;
    int nb = 0;

    while (str[i]) {
        while (my_char_is_alpha(str[i]) == 0 && str[i])
            i++;
        while (my_char_is_alpha(str[i]) == 1 && str[i])
            i++;
        if (my_char_is_alpha(str[i - 1]) == 1)
            nb++;
    }
    return (nb);
}

static int my_len_word(char const *str, int index)
{
    int i = 0;
    int len = 0;
    int current_word = 0;

    while (str[i]) {
        while (my_char_is_alpha(str[i]) == 0 && str[i])
            i++;
        while (my_char_is_alpha(str[i]) == 1 && str[i]) {
            i++;
            len++;
        }
        if (current_word == index)
            return (len + 1);
        i++;
        current_word++;
        len = 0;
    }
    return (0);
}

static char **my_full_fill_tab(char const *str, char **tab)
{
    int x = 0;
    int y = 0;
    int i = 0;

    while (str[i]) {
        while (my_char_is_alpha(str[i]) == 0 && str[i])
            i++;
        while (my_char_is_alpha(str[i]) == 1 && str[i]) {
            tab[x][y] = str[i];
            i++;
            y++;
        }
        while (my_char_is_alpha(str[i]) == 0 && str[i])
            i++;
        tab[x][y] = '\0';
        x++;
        y = 0;
    }
    tab[x] = NULL;
    return (tab);
}

char **my_str_to_word_array_m(char const *str)
{
    int nb_words = 0;
    char **tab = NULL;
    int i = 0;

    if (str == 0)
        return (0);
    while (my_char_is_alpha(str[i]) == 0 && str[i] != '\0')
        i++;
    if (str[i] == '\0')
        return (0);
    nb_words = my_count_words(str);
    tab = malloc(sizeof(char *) * (nb_words + 2));
    if (tab == 0)
        return (0);
    for (int j = 0; j < nb_words; j++) {
        tab[j] = malloc(my_len_word(str, j) * sizeof(char));
    }
    my_full_fill_tab(str, tab);
    return (tab);
}
