/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** add_tree
*/

#include "sh.h"

void cut_string(char **tab, link_t **tree, size_t i);

void create_cell(char **tab, size_t i, link_t **tree)
{
    Tree_t *cell = malloc(sizeof(Tree_t));
    link_t *next = NULL;

    if (!cell)
        return;
    cell->name = my_strdup(tab[i]);
    if (!cell->name) {
        free(cell);
        return;
    }
    cell->stack = 0;
    cell->next = NULL;
    next = create_link(cell);
    list_append(tree, next);
    cut_string(tab, &(cell->next), i + 1);
}

void cut_string(char **tab, link_t **tree, size_t i)
{
    link_t *actual = *tree;
    Tree_t *node = NULL;

    if (!tab[i])
        return;
    do {
        if (!actual)
            continue;
        node = (Tree_t *) actual->obj;
        if (strcmp(node->name, tab[i]) == 0) {
            i++;
            node->stack++;
            cut_string(tab, &(node->next), i++);
            return;
        }
        actual = actual->next;
    } while (*tree && actual != *tree);
    create_cell(tab, i, tree);
}

void add_tree(char *str, sh_t *sh)
{
    char **tab = NULL;

    tab = my_str_word_array(str, ' ');
    cut_string(tab, &(sh->tree), 0);
    if (sh->active) {
        printf("%s : ", sh->name_bot);
        print_tree(tab, &(sh->tree), 0);
        printf("\n");
    }
    my_two_free(tab);
}
