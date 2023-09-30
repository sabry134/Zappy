/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_sgt.c
*/

#include <stdio.h>
#include "zappy_server.h"

void graphical_sgt(zappy_client_t *client, char *)
{
    dprintf(client->sockfd, "sgt %d\n", client->server->freq);
}
