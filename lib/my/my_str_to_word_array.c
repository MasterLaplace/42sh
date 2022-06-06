/*
** EPITECH PROJECT, 2022
** B-PSU-101-REN-1-1-minishell2-killian.bourhis
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static int count_words(char *str, const char *delim)
{
    char *str_dup = NULL;
    int count = 0;

    if (!str)
        return 0;
    str_dup = my_strdup(str);
    if (my_strtok(str_dup, delim))
        count++;
    while (my_strtok(NULL, delim))
        count++;
    free(str_dup);
    return count;
}

char **my_str_to_word_array(char *str, const char *delim)
{
    int len = count_words(str, delim);
    char **words = malloc(sizeof(char *) * (len + 1));
    char *str_dup;

    if (len == 0) {
        free(words);
        return (NULL);
    }
    str_dup = my_strdup(str);
    words[0] = my_strdup(my_strtok(str_dup, delim));
    for (int i = 1; i < len; i++)
        words[i] = my_strdup(my_strtok(NULL, delim));
    words[len] = NULL;
    free(str_dup);
    return words;
}
