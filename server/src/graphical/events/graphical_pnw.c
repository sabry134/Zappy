/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_pnw.c
*/

#include <stdio.h>
#include "zappy_server.h"

void graphical_pnw(zappy_server_t *server, zappy_player_t *player)
{
    graphical_write(server, "pnw %d %u %u %u %d %s\n"
            , player->id
            , player->x
            , player->y
            , player->rot
            , player->lvl
            , player->team->name);
}

void graphical_pnw_c(zappy_client_t *client, zappy_player_t *player)
{
    dprintf(client->sockfd, "pnw %d %u %u %u %d %s\n"
            , player->id
            , player->x
            , player->y
            , player->rot
            , player->lvl
            , player->team->name);
}
