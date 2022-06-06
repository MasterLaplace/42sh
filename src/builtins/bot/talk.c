/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** talk
*/

#include "sh.h"

extern const char *quit_message[];
extern const char *hi_message[];
extern const char *help_message[];
extern const char *do_message[];
extern const char *what_message[];

static const talk_t talk_message[] = {
    {quit_message, "For stop talking to me, type 'bot -d'."},
    {hi_message, "Nice to meet you."},
    {help_message, "For help go see the bot..."},
    {do_message, "nothing ..."},
    {what_message, "I'm just like you, something that responds to messages."},
    {NULL, NULL}
};

bool send_message(char *data, char **message, size_t j, sh_t *sh)
{
    for (size_t i = 0; message[i]; i++) {
        if (strcmp(message[i], data) == 0) {
            printf("%s : %s\n", sh->name_bot, talk_message[j].value);
            return true;
        }
    }
    return false;
}

bool check_message(size_t i, char **message, sh_t *sh)
{
    for (size_t j = 0; talk_message[i].key[j]; j++) {
        if (send_message((char *) talk_message[i].key[j], message, i, sh))
            return true;
    }
    return false;
}

bool talk(char **message, sh_t *sh)
{
    if (strcmp(message[0], "bot") == 0) {
        activate(message, sh);
        return true;
    }
    if (!sh->active)
        return false;
    for (size_t i = 0; talk_message[i].value; i++)
        if (check_message(i, message, sh))
            return true;
    return false;
}
