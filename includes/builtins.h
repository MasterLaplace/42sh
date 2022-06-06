/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** builtins
*/

#ifndef BUILTINS_H_
    #define BUILTINS_H_
    #include "sh.h"

typedef struct sh_s sh_t;
typedef struct chunk_s chunk_t;

typedef struct my_alias_s {
    char *name;
    char *arg;
} alias_t;

typedef struct my_env_s {
    char *key;
    char *value;
} my_env_t;

typedef struct my_var_s {
    char *key;
    char *value;
} var_t;

typedef struct my_talk_s {
    const char **key;
    char *value;
} talk_t;

typedef struct Tree_s {
    link_t *next;
    char *name;
    size_t stack;
} Tree_t;

typedef struct my_builtins_s {
    char *flag;
    int (*redirect)(char **, sh_t *);
} builtins_t;

bool check_builtins(chunk_t *chunk, sh_t *sh);
bool is_builtin_can_fork(chunk_t *chunk, sh_t *sh);
/* MEME */
int builtin_meme(char **tab, sh_t *);

/* BOT */
void activate(char **dest, sh_t *sh);
bool talk(char **message, sh_t *sh);
void add_tree(char *str, sh_t *sh);
void print_tree(char **tab, link_t **tree, int i);

/* CD */
int builtin_cd(char **dest, sh_t *);

/* EXIT */
int builtin_exit(char **dest, sh_t *sh);

/* ENV */
int builtin_env(char **, sh_t *);
int builtin_setenv(char **, sh_t *);
int builtin_unsetenv(char **, sh_t *);

/* MAN */
int check_mans(char **tab, sh_t *);

/* HISTORY */
char **load_history(void);
int print_history(char **, sh_t *);
int add_to_history(char *str);
char *check_reminder(char *str);
char *check_two_reminder(char *str);
bool exist_redirection(char *line, char sign);
char *itos(int nb);
int my_nblen(int nb);
void negative_nb(int nb, char *nb_str);

/* ALIAS */
int add_alias(char **av);
char *check_alias(char *av);
int manage_alias(char **av, sh_t *);
bool norm(char *history, char *command);

/* VAR */
int manage_var(char **argv, sh_t *sh);
int add_var(char **argv, sh_t *sh);
char *check_var(char *command, sh_t *sh);
#endif/* !BUILTINS_H_ */
