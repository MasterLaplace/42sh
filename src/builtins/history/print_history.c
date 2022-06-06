/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** print_history
*/

#include "sh.h"

static char **get_file_lines(struct stat str)
{
    char *str1 = NULL;
    char **tmp = NULL;
    int fd = open(".cache/.history", O_RDONLY);

    if (fd == -1)
        return NULL;
    stat(".cache/.history", &str);
    if (str.st_size == 0)
        return (NULL);
    str1 = malloc(sizeof(char) * (str.st_size + 2));
    if (!str1)
        exit(84);
    memset(str1, '\0', str.st_size + 1);
    read(fd, str1, str.st_size);
    close(fd);
    tmp = my_str_to_word_array_m(str1);
    free(str1);
    return tmp;
}

static void print_history_n(char **file, unsigned int i)
{
    unsigned int j = 0;

    for (j = 0; exist_redirection(file[i + j], ':') == 0; j++)
        printf(" %s", file[i + j]);
    printf("\n");
}

int print_history(UNUSED char **tab, UNUSED sh_t *sh)
{
    struct stat str;
    char **file = get_file_lines(str);
    int nb = 1;

    if (!file)
        return (0);
    for (unsigned int i = 0; file[i] != NULL; i++) {
        if (exist_redirection(file[i], ':') == 1) {
            file[i][strlen(file[i])] = '\0';
            printf("%d\t%s\t", nb, file[i]);
            i++;
            print_history_n(file, i);
            nb++;
        }
    }
    my_two_free(file);
    return (0);
}

int my_nblen(int nb)
{
    int i = 0;
    int tmp = nb;

    if (nb == 0)
        return 1;
    for (; tmp > 0; i++) {
        tmp = tmp / 10;
    }
    for (; tmp < 0; i++) {
        tmp = tmp / 10;
    }
    return i;
}

void negative_nb(int nb, char *nb_str)
{
    if (nb < 0) {
        nb_str[0] = '-';
        nb *= -1;
    }
}
