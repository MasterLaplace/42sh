/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** add_command
*/

#include "sh.h"
#include <time.h>

int add_to_history(char *str)
{
    static const char *filename = ".cache/.history";
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char *tmp = my_append(itos(tm.tm_hour), ':');
    int fd = 0;

    fd = open(filename,  O_CREAT | O_RDWR | O_APPEND, S_IRUSR);
    if (fd == -1)
        return (84);
    tmp = my_strcat(itos(tm.tm_min), tmp);
    tmp = my_append(tmp, ' ');
    tmp = my_strcat(str, tmp);
    tmp = my_append(tmp, '\n');
    write(fd, tmp, strlen(tmp));
    free(tmp);
    close(fd);
    return (0);
}
