/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** operators
*/

#ifndef OPERATORS_H_
    #define OPERATORS_H_
    #include "sh.h"

typedef enum {
    SEMICOLON,
    AND,
    OR,
    D_REDIRECT_R,
    D_REDIRECT_L,
    REDIRECT_R,
    REDIRECT_L,
    PIPE,
    END
} type_flag;

typedef struct chunk_s {
    char **arg;
    type_flag operator;
    bool fork;
    bool error;
} chunk_t;

typedef struct fork_s {
    char *av;
    bool can_fork;
    bool with_arg;
} check_fork_t;

typedef struct flags_s {
    type_flag operator;
    void (*redirect)(char **, sh_t *);
} flags_t;

void check_operators(char *str, sh_t *sh);
void handle_operators(link_t *link, chunk_t *next, sh_t *sh);
bool handle_redirect(link_t *link, chunk_t *next, sh_t *sh);
bool handle_pipe(link_t *link, chunk_t *prev, sh_t *sh);
#endif/* !OPERATORS_H_ */
