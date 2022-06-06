/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** handling_flags
*/

#include "sh.h"

static bool handle_and_and_or(chunk_t *chunk, chunk_t *prev_chunk, sh_t *sh)
{
    pid_t pid = 0;

    if (prev_chunk->operator == AND && sh->status != 0)
        return true;
    if (chunk->operator != OR && chunk->operator != AND)
        return false;
    if (check_builtins(chunk, sh))
        return true;
    if ((pid = fork()) == 0) {
        if (is_builtin_can_fork(chunk, sh))
            exit(sh->status);
        launch(chunk->arg, sh);
    } else
        waitpid(pid, &(sh->status), 0);
    if (WIFSIGNALED(sh->status))
        print_exec_error(WTERMSIG(sh->status), sh->status);
    return true;
}

void handle_other(chunk_t *chunk, sh_t *sh)
{
    pid_t pid = 0;

    if (chunk->operator != SEMICOLON && chunk->operator != END)
        return;
    if (check_builtins(chunk, sh))
        return;
    if ((pid = fork()) == 0) {
        if (is_builtin_can_fork(chunk, sh))
            exit(sh->status);
        launch(chunk->arg, sh);
    } else
        waitpid(pid, &(sh->status), 0);
    if (WIFSIGNALED(sh->status))
        print_exec_error(WTERMSIG(sh->status), sh->status);
}

void handle_operators(link_t *link, chunk_t *next_chunk, sh_t *sh)
{
    chunk_t *chunk = (chunk_t *) link->obj;
    link_t *prev = link->prev;
    chunk_t *prev_chunk = (chunk_t *) prev->obj;

    if (my_strcmp(chunk->arg[0], "exit") == 0)
        if (builtin_exit(chunk->arg, sh))
            return;
    if (talk(chunk->arg, sh))
        return;
    if (handle_and_and_or(chunk, prev_chunk, sh))
        return;
    if (!handle_redirect(link, next_chunk, sh))
        return;
    if (handle_pipe(link, prev_chunk, sh))
        return;
    handle_other(chunk, sh);
}
