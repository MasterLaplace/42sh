/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** check_two_reminder
*/

#include "sh.h"

static char *
rebuilt(const char *command, char *old_command, size_t len1, size_t len2)
{
    size_t len = len1 + len2 + strlen(old_command);
    size_t i = 0;
    size_t x = 0;
    size_t e = 0;
    size_t len_c = strlen(command);
    char *new = calloc(len, sizeof(char));

    for (; i < len1 && command[i]; i++)
        new[i] = command[i];
    for (; old_command[x]; i++, x++)
        new[i] = old_command[x];
    for (e = len_c - len2; e < len_c + len2 && command[e]; i++, e++)
        new[i] = command[e];
    new[i] = '\0';
    return new;
}

char *check_two_reminder(char *command)
{
    char **history = load_history();
    char *new_command = NULL;

    if (!history)
        return command;
    for (size_t i = 0; command[i]; i++) {
        if (my_strncmp(&command[i], "!!", 2) == 0) {
            new_command = rebuilt(command,
            &history[my_two_len(history) - 1][6], i, strlen(&command[i + 2]));
            my_two_free(history);
            free(command);
            return new_command;
        }
    }
    my_two_free(history);
    return command;
}

bool exist_redirection(char *line, char sign)
{
    if (!line)
        return true;
    for (size_t i = 0; i < strlen(line); i++)
        if (line[i] == sign)
            return true;
    return false;
}

char *itos(int nb)
{
    int len = my_nblen(nb);
    if (len == 1)
        len = 2;
    int tmp = 0;
    char *nb_str = malloc(sizeof(char) * len + 1);

    if (!nb_str)
        return NULL;
    negative_nb(nb, nb_str);
    for (int i = len; i > 0; i--) {
        tmp = nb;
        tmp %= 10;
        nb_str[i - 1] = tmp + '0';
        nb /= 10;
    }
    nb_str[len] = '\0';
    return nb_str;
}
