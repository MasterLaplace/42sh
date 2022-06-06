/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** prompt
*/

#include <getopt.h>
#include <ctype.h>
#include <string.h>
#include "sh.h"

extern const style_t colors[];
extern const style_t styles[];

static const char help_prompt[] =
    "Usage: prompt [OPTION]\n\nOptions:\n"
    "    -h, --help\t\tDisplay this help\n"
    "    -c, --dir-color\tSet folder display color (see colors below)\n"
    "    -s, --dir-style\tSet folder display style (see styles below)\n"
    "    -a, --arrow-color\tSet the arrow display color (see colors below)\n"
    "    -r, --arrow-style\tSet arrow display style (see styles below)\n\n"
    "Colors: black, red, green, yellow, "
    "blue, purple, cyan, white, neutral.\n"
    "Styles: normal, bold, dim, italic, "
    "underlined, blinking, reverse, invisible.\n";

static const char help_color[] = "Invalid color. Please enter one of the "
                                "following colors: black, red, green, yellow,"
                                " blue, purple, cyan, white, neutral\n";
static const char help_style[] = "Invalid style. Please enter one of the "
                                "following styles: normal, bold, dim, italic,"
                                " underlined, blinking, reverse, invisible\n";

static const struct option options[] = {
    {"help", no_argument, 0, 'h'},
    {"prompt", required_argument, 0, 'p'},
    {"dir-color", required_argument, 0, 'c'},
    {"dir-style", required_argument, 0, 's'},
    {"arrow-color", required_argument, 0, 'a'},
    {"arrow-style", required_argument, 0, 'r'},
    {0, 0, 0, 0}
};

void set_color(UNUSED sh_t *sh, char **obj)
{
    for (int i = 0; colors[i].name; i++) {
        if (strcmp(my_strlowcase(optarg), colors[i].name) == 0) {
            *obj = colors[i].code;
            return;
        }
    }
    printf("%s", help_color);
}

void set_style(UNUSED sh_t *sh, char **obj)
{
    for (int i = 0; styles[i].name; i++) {
        if (strcmp(my_strlowcase(optarg), styles[i].name) == 0) {
            *obj = styles[i].code;
            return;
        }
    }
    printf("%s", help_style);
}

void modify_prompt(sh_t *sh)
{
    free(sh->style.prompt);
    sh->style.prompt = malloc(sizeof(char) * (my_strlen(optarg) + 3));
    if (!sh->style.prompt) {
        sh->style.prompt = strdup(" ➜ ");
        return;
    }
    sh->style.prompt = my_strcat(my_strcat(" ", optarg), " ");
}

int personalize_prompt(char **argv, sh_t *sh)
{
    int opt = -1;
    int argc = (int) my_two_len(argv);

    while ((opt = getopt_long(argc, argv, "hc:s:a:r:p:",
        options, NULL)) != -1) {
        if (opt == 'h')
            printf("%s", help_prompt);
        if (opt == 'p')
            modify_prompt(sh);
        if (opt == 'c')
            set_color(sh, &STYLE.dir_color);
        if (opt == 's')
            set_style(sh, &STYLE.dir_style);
        if (opt == 'a')
            set_color(sh, &STYLE.arrow_color);
        if (opt == 'r')
            set_style(sh, &STYLE.arrow_style);
    }
    optind = 1;
    return (0);
}

void put_prompt(sh_t *sh)
{
    char *path = getcwd(NULL, 0);
    char **cut_path = NULL;
    char *current_dir = NULL;

    if (!path)
        return;
    cut_path = my_str_to_word_array(path, "/");
    if (!cut_path)
        current_dir = "/";
    else
        current_dir = cut_path[my_two_len(cut_path) - 1];
    printf("%s%s%s\033[0m", STYLE.dir_style, STYLE.dir_color, current_dir);
    printf(" [%d]\033[0m", sh->status);
    printf("%s%s%s\033[0m", STYLE.arrow_style, STYLE.arrow_color,
        STYLE.prompt);
    my_two_free(cut_path);
    free(path);
}
