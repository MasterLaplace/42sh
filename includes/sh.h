/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** sh
*/

#ifndef SH_H_
    #define SH_H_
    #define EXIT_84 84
    #define UNUSED __attribute__((unused))
    #define STYLE sh->style
    #define NB_COLORS 9
    #define NB_STYLES 8
    #include <stdio.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <errno.h>
    #include <string.h>
    #include <curses.h>
    #include "my.h"
    #include "my_printf.h"
    #include "linked.h"
    #include "builtins.h"
    #include "operators.h"

enum color {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    PURPLE,
    CYAN,
    WHITE,
    NEUTRAL
};

enum style {
    NORMAL,
    BOLD,
    DIM,
    ITALIC,
    UNDERLINED,
    BLINKING,
    REVERSE,
    INVISIBLE
};

typedef struct style_s {
    char *name;
    char *code;
} style_t;

typedef struct sh_style_s {
    char *prompt;
    char *dir_color;
    char *dir_style;
    char *arrow_color;
    char *arrow_style;
} sh_style_t;

typedef struct sh_s {
    link_t *env;
    link_t *chunks;
    link_t *var;
    link_t *tree;
    int fd[2];
    char **ev;
    int status;
    bool active;
    char *name_bot;
    char **script;
    sh_style_t style;
} sh_t;

void put_prompt(sh_t *sh);
void init_style(sh_t *sh);
char **read_stdin(void);
bool exec_script(sh_t *sh);
int personalize_prompt(char **argv, sh_t *sh);
void flags_sh(char **av, char **ev);
void init_sh(sh_t *sh, char **ev);
char *verif_path(char *str, sh_t *);
my_env_t *find_env_var(sh_t *sh, char *var);
void parth_string(sh_t *, char *);
int launch(char **av, sh_t *sh);
void print_exec_error(int sig, int status);
void exec_error(char **args);
void free_env(sh_t *);
void clean_env(sh_t *);
void free_chunk(sh_t *);
void clean_chunk(sh_t *);
void free_sh(sh_t *);
void free_style(sh_t *sh);
#endif/* !SH_H_ */
