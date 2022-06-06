/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** builtin_meme
*/

#include "sh.h"

static const char *help[] = {
    "HELP: (meme :id)\n",
    "   1 :\tamongus batman",
    "   2 :\tubuntu logo",
    "   3 :\thog rider",
    "   4 :\tpeacefuly frogger",
    "   5 :\tkawai gun",
    "   6 :\tawakening",
    "   7 :\tgiga chad",
    "   8 :\tSUS",
    NULL
};

int builtin_meme(char **tab, UNUSED sh_t *sh)
{
    my_init_seed();
    if (my_two_len(tab) < 3)
        if (my_strcmp(tab[1], "-h") == 0 || my_strcmp(tab[1], "--help") == 0)
            my_two_put((char **) help);
        else
            my_meme(my_getnbr(tab[1]));
    else {
        printf("meme: too many arguments.\n");
        return (1);
    }
    return (0);
}
