/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** remove_link
*/

#include "linked.h"

void list_remove(link_t **list, link_t *link)
{
    if (!list || !*(list) || !link)
        return;
    if (link->next == link) {
        *list = NULL;
        free(link);
        return;
    }
    if (link == *list)
        *list = (*list)->next;
    (link->next)->prev = link->prev;
    (link->prev)->next = link->next;
    free(link);
}
