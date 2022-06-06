/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** add_alias
*/

#include "sh.h"

int add_alias(char **argv)
{
    static const char *filename = ".cache/.alias";
    char *tmp = NULL;
    int fd = 0;
    unsigned int i = 2;

    fd = open(filename,  O_CREAT | O_RDWR | O_APPEND, S_IRUSR);
    if (fd == -1)
        return (1);
    if (my_two_len(argv) == 1)
        return (0);
    tmp = my_append(argv[1], '=');
    for (; argv[i]; i++) {
        tmp = my_strcat(argv[i], tmp);
        tmp = my_append(tmp, ' ');
    }
    tmp[strlen(tmp) - 1] = '\n';
    write(fd, tmp, strlen(tmp));
    free(tmp);
    close(fd);
    return (0);
}
