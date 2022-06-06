/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** handling_man
*/

#include "sh.h"

extern const size_t NB_MAN;
extern const char *TEXT_MAN[];

static const char *mans[] = {
    "laplace",
    "ligne_b",
    "me",
    NULL
};

static bool verif_mans(char **av, UNUSED sh_t *sh)
{
    for (size_t i = 0; mans[i]; i++)
        if (my_strcmp(av[1], mans[i]) == 0) {
            my_putstr(TEXT_MAN[i]);
            return true;
        }
    return false;
}

int check_mans(char **tab, sh_t *sh)
{
    if (verif_mans(tab, sh))
        return (0);
    if (my_two_len(tab) > 1) {
        printf("No manual entry for %s\n", tab[1]);
        return (1);
    }
    printf("What me page do you want?\nFor example, try 'me me'.\n");
    return (0);
}
