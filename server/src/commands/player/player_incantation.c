/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** player_incantation.c
*/

#include <stdio.h>
#include "zappy_server.h"

static int meet_conditions(zappy_client_t *client, int elevation, int *pls)
{
    static int elev[7][7] = {
        { 1, 1, 0, 0, 0, 0, 0 }, { 2, 1, 1, 1, 0, 0, 0 },
        { 2, 2, 0, 1, 0, 2, 0 }, { 4, 1, 1, 2, 0, 1, 0 },
        { 4, 1, 2, 1, 3, 0, 0 }, { 6, 1, 2, 3, 0, 1, 0 },
        { 6, 2, 2, 2, 2, 2, 1 }
    };
    int l = client->player.lvl - 1;
    int x = client->player.x;
    int y = client->player.y;
    int *unit = client->server->map[y][x];

    if (pls != NULL)
        *pls = elev[l][0];
    if (nb_players_incantation(client, elevation) >= elev[l][0]
            && unit[1] >= elev[l][1] && unit[2] >= elev[l][2]
            && unit[3] >= elev[l][3] && unit[4] >= elev[l][4]
            && unit[5] >= elev[l][5] && unit[6] >= elev[l][6])
        return 1;
    return 0;
}

static int can_elevate(zappy_client_t *client, int elevation, int *pls)
{
    return client->player.lvl < 8 && meet_conditions(client, elevation, pls);
}

int can_elevation_start(zappy_client_t *client)
{
    int pls = 0;

    if (already_incantating(client) || !can_elevate(client, 0, &pls)) {
        dprintf(client->sockfd, "ko\n");
        return 0;
    }
    graphical_pic(client->server, client);
    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS && pls > 0; ++i) {
        if (player_equals_incantation(client, &client->server->clients[i], 0)
                && client != &client->server->clients[i]) {
            --pls;
            client->server->clients[i].player.elevation = 1;
            add_player_command(&client->server->clients[i]
                    , &client->server->incantation_wait, NULL);
        }
    }
    client->player.elevation = 1;
    dprintf(client->sockfd, "Elevation underway\n");
    return 1;
}

static int win_detector(zappy_client_t *client)
{
    zappy_client_t *target = NULL;
    int nb = 0;

    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        target = &client->server->clients[i];
        if (!(target->sockfd < 0)
                && target->player.id != 0
                && target->player.lvl == 8
                && target->player.team == client->player.team) {
            ++nb;
        }
    }
    return nb >= 6;
}

void player_incantation(zappy_client_t *client, char *)
{
    if (!can_elevate(client, 1, NULL)) {
        dprintf(client->sockfd, "ko\n");
        graphical_pie(client->server, &client->player, 0);
        return;
    }
    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        if (player_equals_incantation(client, &client->server->clients[i], 1)) {
            ++client->server->clients[i].player.lvl;
            client->server->clients[i].player.elevation = 0;
        }
    }
    dprintf(client->sockfd, "Current level: %d\n", client->player.lvl);
    graphical_pie(client->server, &client->player, 1);
    if (win_detector(client)) {
        graphical_seg(client->server, client->player.team->name);
    }
}
