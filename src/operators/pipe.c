/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** pipe
*/

#include "sh.h"

static void init_pipe(chunk_t *chunk, int fd_in, int *fd, chunk_t *next)
{
    dup2(fd_in, 0);
    if (next->operator == REDIRECT_R && chunk->operator == PIPE) {
        dup2(STDIN_FILENO, 1);
    }
    if (chunk->operator == PIPE)
        dup2(fd[1], 1);
    close(fd[0]);
}

static void exec(sh_t *sh, int *fd, int fd_in, link_t *link)
{
    chunk_t *chunk = (chunk_t *) link->obj;
    link_t *link_next = link->next;
    chunk_t *next = (chunk_t *) link_next->obj;
    static pid_t pid = 0;

    pipe(fd);
    if ((pid = fork()) == 0) {
        init_pipe(chunk, fd_in, fd, next);
        if (is_builtin_can_fork(chunk, sh))
            exit(sh->status);
        launch(chunk->arg, sh);
    } else
        waitpid(pid, &(sh->status), 0);
}

bool handle_pipe(link_t *link, chunk_t *prev_chunk, sh_t *sh)
{
    chunk_t *chunk = (chunk_t *) link->obj;
    static int fd[2];
    static int fd_in = 0;

    if (chunk->operator != PIPE && prev_chunk->operator != PIPE)
        return false;
    if (check_builtins(chunk, sh))
        return true;
    exec(sh, fd, fd_in, link);
    if (WIFSIGNALED(sh->status))
        print_exec_error(WTERMSIG(sh->status), sh->status);
    close(fd[1]);
    fd_in = fd[0];
    return true;
}
