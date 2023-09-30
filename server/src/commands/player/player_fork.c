/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** player_fork.c
*/

#include <stdio.h>
#include "zappy_server.h"

int egg_laying(zappy_client_t *client)
{
    graphical_pfk(client->server, &client->player);
    return 1;
}

void player_fork(zappy_client_t *client, char *)
{
    zappy_egg_t *egg = spawn_egg(client);

    if (egg != NULL) {
        dprintf(client->sockfd, "ok\n");
        graphical_enw(client->server, egg);
    } else {
        dprintf(client->sockfd, "ko\n");
    }
}
