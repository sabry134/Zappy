/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** player_broadcast.c
*/

#include <stdio.h>
#include "zappy_server.h"

static void check_direction(zappy_client_t *cli, zappy_client_t *client)
{
    int x = client->player.x - cli->player.x;
    int y = client->player.y - cli->player.y;
    int direction = x + y;

    if ((60 - direction) < direction) {
        x = -x;
        y = -y;
    }
    if (cli->player.rot == 1)
        print_direction_nord(cli, x, y);
    if (cli->player.rot == 2)
        print_direction_east(cli, x, y);
    if (cli->player.rot == 3)
        print_direction_sud(cli, x, y);
    if (cli->player.rot == 4)
        print_direction_west(cli, x, y);
}

void broadcast(zappy_client_t *client, char *data)
{
    zappy_client_t *cli = NULL;

    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        cli = &client->server->clients[i];
        if (!(cli->sockfd < 0)
                && cli->player.id != 0
                && cli->sockfd != client->sockfd) {
            dprintf(cli->sockfd, "message ");
            check_direction(cli, client);
            dprintf(cli->sockfd, "%s\n", data);
        }
    }
    dprintf(client->sockfd, "ok\n");
    graphical_pbc(client->server, &client->player, data);
}
