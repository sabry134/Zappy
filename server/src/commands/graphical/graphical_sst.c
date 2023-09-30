/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_sst.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zappy_server.h"

void graphical_sst(zappy_client_t *client, char *data)
{
    char *freq = data;

    if (data != NULL && strstr(data, " ") == NULL && is_number(freq)) {
        client->server->freq = atoi(freq);
        dprintf(client->sockfd, "sst %d\n", client->server->freq);
    } else {
        dprintf(client->sockfd, "sbp\n");
    }
}
