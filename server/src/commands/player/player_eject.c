/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** player_eject.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "zappy_server.h"

static int destroy_eggs(zappy_client_t *client, zappy_team_t *team)
{
    zappy_egg_t **egg = &team->eggs;
    zappy_egg_t *curr_egg = NULL;
    int res = 0;

    while (*egg != NULL) {
        curr_egg = *egg;
        if (client->player.x == (*egg)->x && client->player.y == (*egg)->y) {
            *egg = (*egg)->next;
            graphical_edi(client->server, curr_egg);
            free(curr_egg);
            res = 1;
        }
        egg = &(*egg)->next;
    }
    return res;
}

static int looking_for_eggs(zappy_client_t *client)
{
    zappy_team_t *next_team = client->server->teams;
    int res = 0;

    while (next_team != NULL) {
        if (next_team != client->player.team
                && destroy_eggs(client, next_team)) {
            res = 1;
        }
        next_team = next_team->next;
    }
    return res;
}

static int eject_players(zappy_client_t *client)
{
    zappy_client_t *target = NULL;
    int res = 0;

    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        target = &client->server->clients[i];
        if (!(target->sockfd < 0)
                && target->player.id != 0
                && target != client
                && target->player.team != client->player.team
                && target->player.x == client->player.x
                && target->player.y == client->player.y) {
            forward(target, client->player.rot);
            dprintf(target->sockfd, "eject: %d\n", client->player.rot);
            graphical_pex(client->server, &target->player);
            res = 1;
        }
    }
    return res;
}

void player_eject(zappy_client_t *client, char *)
{
    if (eject_players(client) || looking_for_eggs(client)) {
        dprintf(client->sockfd, "ok\n");
    } else {
        dprintf(client->sockfd, "ko\n");
    }
}
