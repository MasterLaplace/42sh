/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** builtin_cd
*/

#include "sh.h"

static void print_error(char *path)
{
    if (errno == ENOENT)
        printf("%s: No such file or directory.\n", path);
    if (errno == ENOTDIR)
        printf("%s: Not a directory.\n", path);
    if (errno == EACCES)
        printf("%s: Permission denied.\n", path);
}

static void cd_print_error(char *const *dest)
{
    if (chdir(*dest) == -1)
        print_error(*dest);
}

int builtin_cd(char **dest, sh_t *sh)
{
    static char *old_pwd = NULL;
    my_env_t *variable = find_env_var(sh, "HOME");

    if (my_two_len(dest) > 2) {
        printf("cd: Too many arguments.\n");
        return (1);
    }
    dest++;
    if (!dest | !*dest) {
        if (!variable || !variable->value) {
            printf("%s\n", "cd: No home directory.");
            return (1);
        }
        *dest = variable->value;
    }
    if (strcmp(*dest, "-") == 0)
        *dest = old_pwd;
    old_pwd = getcwd(NULL, 0);
    cd_print_error(dest);
    return (0);
}
