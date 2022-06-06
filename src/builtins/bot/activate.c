/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** activate
*/

#include "sh.h"

void rename_bot(char *name, sh_t *sh)
{
    if (!name || !*name)
        return;
    if (sh->name_bot || *(sh->name_bot))
        free(sh->name_bot);
    sh->name_bot = strdup(name);
}

void activate(char **dest, sh_t *sh)
{
    char *name = getenv("USER");

    if (my_two_len(dest) >= 2) {
        if (strcmp(dest[1], "rename") == 0 || strcmp(dest[1], "-r") == 0)
            rename_bot(dest[2], sh);
        if (!sh->active &&
            (strcmp(dest[1], "activate") == 0 || strcmp(dest[1], "-a") == 0)) {
            sh->active = true;
            printf("%s : Hello %s, what can i do for you ?\n",
            sh->name_bot, name);
        } else if (sh->active && (strcmp(dest[1], "desactivate") == 0 ||
            strcmp(dest[1], "-d") == 0)) {
            sh->active = false;
            printf("%s : see you later !\n", sh->name_bot);
        }
    }
}
