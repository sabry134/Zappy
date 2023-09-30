/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_pic.c
*/

#include "zappy_server.h"

void graphical_pic(zappy_server_t *server, zappy_client_t *client)
{
    graphical_write(server, "pic %u %u %d"
            , client->player.x
            , client->player.y
            , client->player.lvl);
    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        if (player_equals_incantation(client, &client->server->clients[i], 0)) {
            graphical_write(server, " %d", server->clients[i].player.id);
        }
    }
    graphical_write(server, "\n");
}
