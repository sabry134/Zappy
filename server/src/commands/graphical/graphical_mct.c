/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_mct.c
*/

#include "zappy_server.h"

void graphical_mct(zappy_client_t *client, char *)
{
    for (int y = 0; y < client->server->height; ++y) {
        for (int x = 0; x < client->server->width; ++x) {
            tile_content(client, x, y);
        }
    }
}
