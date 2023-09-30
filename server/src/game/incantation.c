/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** incantation.c
*/

#include "zappy_server.h"

int player_equals_incantation(zappy_client_t *c1, zappy_client_t *c2
, int elevation)
{
    zappy_player_t *p1 = &c1->player;
    zappy_player_t *p2 = &c2->player;

    return !(c1->sockfd < 0) && !(c2->sockfd < 0)
            && p1->id != 0 && p2->id != 0
            && p1->x == p2->x
            && p1->y == p2->y
            && p1->lvl == p2->lvl
            && p1->elevation == elevation
            && p2->elevation == elevation
            && (elevation != 0 || p2->cmds[0].pcmd == NULL);
}

int nb_players_incantation(zappy_client_t *client, int elevation)
{
    int nb = 0;

    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        if (player_equals_incantation(client
                , &client->server->clients[i], elevation)) {
            ++nb;
        }
    }
    return nb;
}

int already_incantating(zappy_client_t *client)
{
    zappy_client_t *cl = NULL;

    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        cl = &client->server->clients[i];
        if (!(cl->sockfd < 0)
                && cl->player.id != 0
                && client->player.x == cl->player.x
                && client->player.x == cl->player.y
                && cl->player.elevation) {
            return 1;
        }
    }
    return 0;
}
