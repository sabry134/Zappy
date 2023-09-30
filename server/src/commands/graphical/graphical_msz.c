/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_msz.c
*/

#include <stdio.h>
#include "zappy_server.h"

void graphical_msz(zappy_client_t *client, char *)
{
    int width = client->server->width;
    int height = client->server->height;

    dprintf(client->sockfd, "msz %d %d\n", width, height);
}
