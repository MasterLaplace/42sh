/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** redirection
*/

#include "sh.h"

static bool exist_file(char *pathname)
{
    struct stat str;

    if (lstat(pathname, &str) == -1) {
        printf("%s: No such file or directory.\n", pathname);
        return false;
    }
    return true;
}

static bool error_message(char *pathname)
{
    struct stat str;

    lstat(pathname, &str);
    if (S_ISDIR(str.st_mode) != 0) {
        printf("%s: Is a directory.\n", pathname);
        return false;
    }
    if (access(pathname, W_OK)) {
        printf("%s: Permission denied\n", pathname);
        return false;
    }
    return true;
}

static void exec(chunk_t *chunk, sh_t *sh, int fd, chunk_t *prev)
{
    pid_t pid = 0;

    if ((pid = fork()) == 0) {
        if (prev->operator == PIPE)
            dup2(fd, STDIN_FILENO);
        else
            dup2(fd, 1);
        if (is_builtin_can_fork(chunk, sh))
            exit(sh->status);
        launch(chunk->arg, sh);
    } else
        waitpid(pid, &(sh->status), 0);
    if (WIFSIGNALED(sh->status))
        print_exec_error(WTERMSIG(sh->status), sh->status);
    dup2(1, fd);
    close(fd);
}

static bool
temp_redirection(char *pathname, chunk_t *chunk, sh_t *sh, chunk_t *prev)
{
    int fd = 0;

    if (chunk->operator == REDIRECT_L)
        if (!exist_file(pathname))
            return false;
    fd = open(pathname, O_CREAT | O_RDWR | O_APPEND, 0777);
    if (!error_message(pathname))
        return false;
    if (chunk->operator == REDIRECT_R)
        fd = open(pathname, O_CREAT | O_RDWR | O_TRUNC, 0777);
    if (chunk->operator == D_REDIRECT_R)
        fd = open(pathname, O_CREAT | O_RDWR | O_APPEND, 0777);
    if (chunk->operator == REDIRECT_L)
        fd = open(pathname, O_CREAT | O_RDWR | O_TRUNC, 0777);
    if (fd == -1)
        return true;
    exec(chunk, sh, fd, prev);
    return true;
}

bool handle_redirect(link_t *link, chunk_t *next_chunk, sh_t *sh)
{
    chunk_t *chunk = (chunk_t *) link->obj;
    link_t *prev = link->prev;
    chunk_t *prev_chunk = (chunk_t *) prev->obj;

    if (prev_chunk->operator == D_REDIRECT_L
        || prev_chunk->operator == D_REDIRECT_R
        || prev_chunk->operator == REDIRECT_L
        || prev_chunk->operator == REDIRECT_R)
        return false;
    if (chunk->operator == D_REDIRECT_L
        || chunk->operator == D_REDIRECT_R
        || chunk->operator == REDIRECT_L
        || chunk->operator == REDIRECT_R) {
        if (!temp_redirection(next_chunk->arg[0], chunk, sh, prev_chunk))
            return false;
        else
            return true;
    }
    return true;
}
