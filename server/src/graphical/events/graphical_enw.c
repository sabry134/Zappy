/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_enw.c
*/

#include <stdio.h>
#include "zappy_server.h"

void graphical_enw(zappy_server_t *server, zappy_egg_t *egg)
{
    graphical_write(server, "enw %d %d %u %u\n"
            , egg->id
            , egg->player_id
            , egg->x
            , egg->y);
}

void graphical_enw_c(zappy_client_t *client, zappy_egg_t *egg)
{
    dprintf(client->sockfd, "enw %d %d %u %u\n"
            , egg->id
            , egg->player_id
            , egg->x
            , egg->y);
}
