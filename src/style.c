/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** style
*/

#include "sh.h"
#include "../includes/sh.h"

const style_t colors[] = {
    {"black", "\033[30m"},
    {"red", "\033[31m"},
    {"green", "\033[32m"},
    {"yellow", "\033[33m"},
    {"blue", "\033[34m"},
    {"purple", "\033[35m"},
    {"cyan", "\033[36m"},
    {"white", "\033[37m"},
    {"neutral", "\033[0m"},
    {NULL, NULL}
};

const style_t styles[] = {
    {"normal", "\033[0m"},
    {"bold", "\033[1m"},
    {"dim", "\033[2m"},
    {"italic", "\033[3m"},
    {"underlined", "\033[4m"},
    {"blinking", "\033[5m"},
    {"reverse", "\033[7m"},
    {"invisible", "\033[8m"},
    {NULL, NULL}
};

void free_style(sh_t *sh)
{
    if (sh->style.prompt)
        free(sh->style.prompt);
}

void init_style(sh_t *sh)
{
    sh->style.prompt = my_strdup(" ➜ ");
    sh->style.dir_color = colors[CYAN].code;
    sh->style.dir_style = styles[BOLD].code;
    sh->style.arrow_color = colors[RED].code;
    sh->style.arrow_style = styles[BLINKING].code;
}
