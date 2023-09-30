/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** player_inventory.c
*/

#include <stdio.h>
#include "zappy_server.h"

void player_inventory(zappy_client_t *client, char *)
{
    dprintf(client->sockfd,
            "[food %d, linemate %d, deraumere %d, sibur %d"
            ", mendiane %d, phiras %d, thystame %d]\n"
            , client->player.inventory[0]
            , client->player.inventory[1]
            , client->player.inventory[2]
            , client->player.inventory[3]
            , client->player.inventory[4]
            , client->player.inventory[5]
            , client->player.inventory[6]);
}
