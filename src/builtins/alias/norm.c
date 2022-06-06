/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** norme
*/

#include "sh.h"

bool norm(char *history, char *command)
{
    char **tmp = my_str_to_word_array(history, "=");

    for (int j = 0; command[j]; j++) {
        if (strncmp(&command[j], *tmp, strlen(*tmp)) == 0
            && (command[j + strlen(*tmp)] == ' '
            || command[j + strlen(*tmp)] == '\t'
            || command[j + strlen(*tmp)] == '\0')) {
            my_two_free(tmp);
            return true;
        }
    }
    my_two_free(tmp);
    return false;
}
