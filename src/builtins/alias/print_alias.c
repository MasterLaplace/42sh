/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** print_alias
*/

#include "sh.h"

char **get_file_lines(struct stat str)
{
    char *str1 = NULL;
    char **tmp = NULL;
    int fd = open(".cache/.alias", O_RDONLY);

    if (fd == -1)
        return (NULL);
    stat(".cache/.alias", &str);
    if (str.st_size == 0)
        return (NULL);
    str1 = malloc(sizeof(char) * (str.st_size + 2));
    if (!str1)
        return (NULL);
    memset(str1, '\0', str.st_size + 1);
    read(fd, str1, str.st_size);
    close(fd);
    tmp = my_str_to_word_array(str1, "\n");
    free(str1);
    return tmp;
}

int print_alias(void)
{
    struct stat str;
    char **file = get_file_lines(str);
    char **tmp = NULL;

    if (!file) {
        printf(".alias: No such file or directory.\n");
        return (1);
    }
    for (unsigned int i = 0; file[i]; i++) {
        tmp = my_str_to_word_array(file[i], "=");
        printf("%s\t(%s)\n", tmp[0], tmp[1]);
        my_two_free(tmp);
    }
    my_two_free(file);
    return (0);
}

int manage_alias(char **argv, UNUSED sh_t *sh)
{
    if (my_two_len(argv) >= 3)
        return add_alias(argv);
    else
        return print_alias();
}
