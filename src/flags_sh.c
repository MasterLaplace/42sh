/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** check_flags
*/

#include "sh.h"

static const char *update[] = {"/bin/make", "update", NULL};
static const char *help[] = {
    "HELP :\n",
    "builtins :",
    "- bot -a/activate  -d/desactivate  -r/rename",
    "- meme *nbr  -h/--help",
    "- me *name",
    NULL
};

void flags_sh(char **av, char **ev)
{
    if (my_strcmp(av[1], "-u") == 0) {
        if (access(update[0], F_OK) == 0) {
            execve(update[0], (char **) update, ev);
            exit(EXIT_SUCCESS);
        }
        exit(EXIT_FAILURE);
    }
    if (my_strcmp(av[1], "-h") == 0) {
        my_two_put((char **) help);
        exit(EXIT_SUCCESS);
    }
}
