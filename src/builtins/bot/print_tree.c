/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** print_tree
*/

#include "sh.h"

void search(link_t **tree)
{
    link_t *actual = *tree;
    Tree_t *node = NULL;
    Tree_t *probality = NULL;

    if (actual)
        probality = (Tree_t *) actual->obj;
    do {
        if (!actual)
            continue;
        node = (Tree_t *) actual->obj;
        if (node->stack > probality->stack)
            probality = node;
        actual = actual->next;
    } while (*tree && actual != *tree);
    if (probality) {
        printf("%s ", probality->name);
        search(&(probality->next));
    }
}

void print_tree(char **tab, link_t **tree, int i)
{
    link_t *actual = *tree;
    Tree_t *node = NULL;

    if (!tab[i])
        return search(tree);
    do {
        if (!actual)
            continue;
        if (!tab[i])
            return;
        node = (Tree_t *) actual->obj;
        if (strcmp(node->name, tab[i]) == 0) {
            printf("%s ", node->name);
            i++;
            print_tree(tab, &(node->next), i);
        }
        actual = actual->next;
    } while (*tree && actual != *tree);
}
