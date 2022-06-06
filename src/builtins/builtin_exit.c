/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** builtin_exit
*/

#include "sh.h"

int builtin_exit(char **dest, UNUSED sh_t *sh)
{
    static int exit_value = EXIT_SUCCESS;

    if (my_two_len(dest) > 1) {
        if (!my_isnum(dest[1])) {
            printf("exit: Expression Syntax.\n");
            return (1);
        }
        exit_value = my_getnbr(dest[1]);
    }
    free_sh(sh);
    if (isatty(STDIN_FILENO))
        printf("exit\n");
    exit(exit_value);
}
