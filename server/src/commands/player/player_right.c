/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** player_right.c
*/

#include <stdio.h>
#include "zappy_server.h"

void player_right(zappy_client_t *client, char *)
{
    client->player.rot = (client->player.rot % 4) + 1;
    dprintf(client->sockfd, "ok\n");
}
