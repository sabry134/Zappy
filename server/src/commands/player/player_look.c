/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** player_look.c
*/

#include <stdio.h>
#include "zappy_server.h"

static long get_map_unit(zappy_client_t *client, int i, int j)
{
    unsigned int x = 0;
    unsigned int y = 0;

    if (client->player.rot == 1) {
        x = modulo(client->player.x + j, client->server->width);
        y = modulo(client->player.y + i, client->server->height);
    }
    if (client->player.rot == 2) {
        x = modulo(client->player.x + i, client->server->width);
        y = modulo(client->player.y + j, client->server->height);
    }
    if (client->player.rot == 3) {
        x = modulo(client->player.x - j, client->server->width);
        y = modulo(client->player.y - i, client->server->height);
    }
    if (client->player.rot == 4) {
        x = modulo(client->player.x - i, client->server->width);
        y = modulo(client->player.y - j, client->server->height);
    }
    return ((long)x << 32) | y;
}

static void display_players(zappy_client_t *client
, unsigned int x, unsigned int y, int *first)
{
    zappy_client_t *target = NULL;

    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        target = &client->server->clients[i];
        if (!(target->sockfd < 0)
                && target->player.id != 0
                && target->player.x == x
                && target->player.y == y) {
            dprintf(client->sockfd, (*first ? "player" : " player"));
            *first = 0;
        }
    }
}

static void display_one_unit(zappy_client_t *client, int i, int j)
{
    long xy = get_map_unit(client, i, j);
    unsigned int x = (xy >> 32);
    unsigned int y = xy;
    int *unit = client->server->map[y][x];
    int first = 1;

    if (i != 0) {
        dprintf(client->sockfd, ",");
    }
    display_players(client, x, y, &first);
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < unit[i]; ++j) {
            dprintf(client->sockfd, (first ? "%s" : " %s")
                    , get_resource_name(i));
            first = 0;
        }
    }
}

void player_look(zappy_client_t *client, char *)
{
    dprintf(client->sockfd, "[");
    for (int i = 0; i <= client->player.lvl; ++i) {
        for (int j = -i; j < (i + 1); ++j) {
            display_one_unit(client, i, j);
        }
    }
    dprintf(client->sockfd, "]\n");
}
