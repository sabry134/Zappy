/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_join.c
*/

#include "zappy_server.h"

static void send_players(zappy_client_t* client)
{
    zappy_client_t *target = NULL;

    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        target = &client->server->clients[i];
        if (!(target->sockfd < 0) && target->player.id != 0) {
            graphical_pnw_c(client, &target->player);
        }
    }
}

static void send_eggs(zappy_client_t* client)
{
    zappy_team_t *team = client->server->teams;
    zappy_egg_t *egg = NULL;

    while (team != NULL) {
        egg = team->eggs;
        while (egg != NULL) {
            graphical_enw_c(client, egg);
            egg = egg->next;
        }
        team = team->next;
    }
}

void graphical_join(zappy_client_t* client)
{
    graphical_msz(client, NULL);
    graphical_sgt(client, NULL);
    graphical_mct(client, NULL);
    graphical_tna(client, NULL);
    send_players(client);
    send_eggs(client);
}
