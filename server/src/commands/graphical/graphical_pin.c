/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_pin.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zappy_server.h"

void graphical_pin(zappy_client_t *client, char *data)
{
    char *id = data;
    zappy_player_t *player = NULL;

    if (data != NULL && strstr(data, " ") == NULL && is_number(id)) {
        player = get_player_by_id(client->server, atoi(id));
        if (player != NULL) {
            dprintf(client->sockfd
                    , "pin %d %d %d %d %d %d %d %d %d %d\n"
                    , player->id , player->x , player->y
                    , player->inventory[0], player->inventory[1]
                    , player->inventory[2], player->inventory[3]
                    , player->inventory[4], player->inventory[5]
                    , player->inventory[6]);
        } else {
            dprintf(client->sockfd, "sbp\n");
        }
    } else {
        dprintf(client->sockfd, "sbp\n");
    }
}
