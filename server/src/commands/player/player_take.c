/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** player_take.c
*/

#include <stdio.h>
#include "zappy_server.h"

void player_take(zappy_client_t *client, char *data)
{
    int i = get_resource_index(data);
    int x = client->player.x;
    int y = client->player.y;

    if (i != -1 && client->server->map[y][x][i] > 0) {
        --client->server->map[y][x][i];
        ++client->player.inventory[i];
        dprintf(client->sockfd, "ok\n");
        graphical_pgt(client->server, &client->player, i);
    } else {
        dprintf(client->sockfd, "ko\n");
    }
}
