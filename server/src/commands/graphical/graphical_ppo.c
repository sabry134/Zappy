/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_ppo.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zappy_server.h"

void graphical_ppo(zappy_client_t *client, char *data)
{
    char *id = data;
    zappy_player_t *player = NULL;

    if (data != NULL && strstr(data, " ") == NULL && is_number(id)) {
        player = get_player_by_id(client->server, atoi(id));
        if (player != NULL) {
            dprintf(client->sockfd
                    , "ppo %d %d %d %d\n"
                    , player->id
                    , player->x
                    , player->y
                    , player->rot);
        } else {
            dprintf(client->sockfd, "sbp\n");
        }
    } else {
        dprintf(client->sockfd, "sbp\n");
    }
}
