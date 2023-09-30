/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_tna.c
*/

#include <stdio.h>
#include "zappy_server.h"

void graphical_tna(zappy_client_t *client, char *)
{
    zappy_team_t *next_team = client->server->teams;

    while (next_team != NULL) {
        dprintf(client->sockfd, "tna %s\n", next_team->name);
        next_team = next_team->next;
    }
}
