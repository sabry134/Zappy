/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** commands_parse.c
*/

#include <stdio.h>
#include <string.h>
#include "zappy_server.h"

void commands_graphical(zappy_client_t* client, char* data)
{
    zappy_gcmd_t *gcmd = NULL;
    char *command_name = data;

    data = strstr(data, " ");
    if (data != NULL) {
        data[0] = '\0';
        ++data;
    }
    for (int i = 0; i < ZAPPY_SERVER_GRAPHICAL_COMMANDS_COUNT; ++i) {
        gcmd = &client->server->graphical_commands[i];
        if (strcmp(gcmd->name, command_name) == 0) {
            gcmd->func(client, data);
            return;
        }
    }
    dprintf(client->sockfd, "suc\n");
}

void commands_player(zappy_client_t* client, char* data)
{
    zappy_pcmd_t *pcmd = NULL;
    char *command_name = data;

    data = strstr(data, " ");
    if (data != NULL) {
        data[0] = '\0';
        ++data;
    } else {
        data = "";
    }
    for (int i = 0; i < ZAPPY_SERVER_PLAYER_COMMANDS_COUNT; ++i) {
        pcmd = &client->server->player_commands[i];
        if (strcmp(pcmd->name, command_name) == 0) {
            add_player_command(client, pcmd, data);
            return;
        }
    }
    dprintf(client->sockfd, "ko\n");
}
