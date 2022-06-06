/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-42sh-guillaume.papineau
** File description:
** init_sh
*/

#include "sh.h"
#include <time.h>

static const char *loading[] = {
    "\033[H\033[J Laoding: [-          ]",
    "\033[H\033[J Laoding: [=-         ]",
    "\033[H\033[J Laoding: [==-        ]",
    "\033[H\033[J Laoding: [===-       ]",
    "\033[H\033[J Laoding: [====-      ]",
    "\033[H\033[J Laoding: [=====-     ]",
    "\033[H\033[J Laoding: [======-    ]",
    "\033[H\033[J Laoding: [=======-   ]",
    "\033[H\033[J Laoding: [========-  ]",
    "\033[H\033[J Laoding: [=========- ]",
    "\033[H\033[J Laoding: [==========-]",
    NULL
};

static int msleep(long tms)
{
    struct timespec ts;
    int ret;

    if (tms < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = tms / 1000;
    ts.tv_nsec = (tms % 1000) * 1000000;

    do {
        ret = nanosleep(&ts, &ts);
    } while (ret && errno == EINTR);

    return ret;
}

static void init_env(sh_t *sh, char **ev)
{
    for (size_t i = 0; ev[i]; i++) {
        my_env_t *variable = malloc(sizeof(my_env_t));

        if ((variable->key = strtok(ev[i], "=")) == NULL)
            variable->key = "";
        if ((variable->value = strtok(NULL, "")) == NULL)
            variable->value = "";
        link_t *link = create_link(variable);
        list_append(&(sh->env), link);
    }
}

void init_sh(sh_t *sh, char **ev)
{
    for (unsigned int i = 0; loading[i]; i++) {
        printf("%s  %u/11\n", loading[i], i);
        msleep(200);
    }
    sh->chunks = NULL;
    sh->env = NULL;
    sh->var = NULL;
    sh->status = 0;
    sh->active = false;
    sh->tree = NULL;
    sh->name_bot = strdup("Bot");
    sh->ev = my_two_dup(ev);
    init_env(sh, ev);
    init_style(sh);
    sh->script = read_stdin();
    my_set_limit();
    printf("\033[H\033[J Complete : ✓\n");
    msleep(600);
}
