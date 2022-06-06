/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** reminder
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

static char *replace(char *command, char *old_command)
{
    size_t i = 0;
    size_t x = 0;
    char *dest = NULL;

    if (!*old_command)
        return strdup(command);
    for (; command[i] != '!' && command[i]; i++);
    if (command[i] == '!')
        for (x = i + 1; command[x] && command[x] >= '0'
            && command[x] <= '9'; x++);
    dest = rebuilt(command, old_command, i, strlen(&command[x]));
    return dest;
}

static int search_in_command(const char *command, int max)
{
    int i = 0;
    int x = 0;
    int nbr = 0;

    if (max == 0)
        return (-1);

    for (; command[i] != '!' && command[i]; i++);
    if (command[i] == '!')
        for (x = i + 1; command[x] >= '0' && command[x] <= '9'; x++)
            nbr = nbr * 10 + command[x] - '0';
    if (nbr > 0 && nbr <= max)
        return nbr;
    return (-1);
}

char **load_history(void)
{
    const char *pathname = ".cache/.history";
    int fd = open(pathname, O_CREAT | O_RDWR | O_APPEND, S_IRUSR);
    struct stat st;
    char *buf = NULL;
    char **tab = NULL;

    stat(pathname, &st);
    if (st.st_size == 0)
        return NULL;
    buf = calloc(st.st_size + 1, sizeof(char));
    if (fd == -1 || !buf)
        return NULL;
    read(fd, buf, st.st_size);
    buf[st.st_size] = '\0';
    tab = my_str_to_word_array(buf, "\n");
    free(buf);
    close(fd);
    return tab;
}

char *check_reminder(char *command)
{
    char **history = load_history();
    char *new_command = NULL;
    int nbr = 0;

    if (!history)
        return command;
    nbr = search_in_command(command, my_two_len(history));
    if (nbr != -1) {
        if (strlen(history[nbr - 1]) < 6) {
            my_two_free(history);
            return command;
        }
        new_command = replace(command, &history[nbr - 1][6]);
        free(command);
        my_two_free(history);
        return new_command;
    }
    my_two_free(history);
    return command;
}
