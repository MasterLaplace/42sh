/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** create_link
*/

#include "linked.h"

link_t *create_link(void *new)
{
    link_t *link = malloc(sizeof(link_t));

    if (!link)
        return (NULL);
    if (!new) {
        free(link);
        return (NULL);
    }
    if (new)
        link->obj = new;
    link->next = link;
    link->prev = link;
    return link;
}
