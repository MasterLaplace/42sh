/*
** EPITECH PROJECT, 2022
** B-PSU-101-REN-1-1-minishell2-killian.bourhis
** File description:
** error
*/

#include "sh.h"

void exec_error(char **args)
{
    if (errno == EACCES)
        printf("%s: Permission denied.\n", args[0]);
    else if (errno == ENOEXEC)
        printf("%s: Exec format error. Wrong Architecture.\n", args[0]);
    else
        printf("%s: Command not found.\n", args[0]);
}

void print_exec_error(int sig, int status)
{
    if (sig == SIGSEGV)
        printf("Segmentation fault");
    if (sig == SIGFPE)
        printf("Floating exception");
    if (sig == SIGILL)
        printf("Illegal instruction");
    if (sig == SIGABRT)
        printf("Abort");
    if (sig == SIGTERM)
        printf("Terminated");
    printf("%s", (WCOREDUMP(status)) ? " (core dumped)\n" : "\n");
}
