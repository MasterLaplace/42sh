/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** core
*/

#include "sh.h"

int launch(char **av, sh_t *sh)
{
    char *path = verif_path(av[0], sh);

    if ((sh->status = access(path, F_OK)) == 0)
        sh->status = execve(path, av, sh->ev);
    if (sh->status == -1)
        exec_error(av);
    exit(EXIT_FAILURE);
}

static void commands(sh_t *sh)
{
    link_t *actual = sh->chunks;
    chunk_t *chunk = NULL;

    if (!actual)
        return;
    do {
        chunk = (chunk_t *) actual->obj;
        actual = actual->next;
        if (chunk->operator == END)
            handle_operators(actual->prev, NULL, sh);
        else
            handle_operators(actual->prev, (chunk_t *) actual->obj, sh);
    } while (sh->chunks && actual != sh->chunks);
}

static void hub(char **buf, size_t size, sh_t *sh)
{
    while (getline(buf, &size, stdin) > 0) {
        if ((*buf)[my_strlen(*buf) - 1] == '\n') {
            parth_string(sh, *buf);
            commands(sh);
        }
        free_chunk(sh);
        if (isatty(STDIN_FILENO))
            put_prompt(sh);
    }
}

int main(UNUSED int ac, UNUSED char **av, char **ev)
{
    char *buf = NULL;
    size_t size = 0;
    sh_t sh;

    flags_sh(av, ev);
    init_sh(&sh, ev);
    printf("\033[H\033[J");
    if (exec_script(&sh))
        return EXIT_SUCCESS;
    if (isatty(STDIN_FILENO))
        put_prompt(&sh);
    hub(&buf, size, &sh);
    free_sh(&sh);
    return EXIT_SUCCESS;
}
