/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** link
*/

#ifndef LINK_H_
    #define LINK_H_
    #include <stddef.h>
    #include <stdlib.h>

typedef struct link_s {
    void *obj;
    struct link_s *next;
    struct link_s *prev;
} link_t;

//* It creates a link with the object passed in parameter.
link_t *create_link(void *new);

//* It adds a link to the list.
void list_append(link_t **list, link_t *link);

//* It removes a link from the list.
void list_remove(link_t **list, link_t *link);
#endif/* !LINK_H_ */
