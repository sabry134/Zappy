/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** player_forward.c
*/

#include <stdio.h>
#include "zappy_server.h"

void forward(zappy_client_t *client, int rot)
{
    if (rot == 1) {
        ++client->player.y;
    }
    if (rot == 2) {
        ++client->player.x;
    }
    if (rot == 3) {
        --client->player.y;
    }
    if (rot == 4) {
        --client->player.x;
    }
    client->player.x = modulo(client->player.x, client->server->width);
    client->player.y = modulo(client->player.y, client->server->height);
}

void player_forward(zappy_client_t *client, char *)
{
    forward(client, client->player.rot);
    dprintf(client->sockfd, "ok\n");
}
