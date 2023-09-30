/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** game_loop.c
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "zappy_server.h"

static void player_hunger(zappy_client_t *client)
{
    if (time_is_up(client->server
            , client->player.hunger, ZAPPY_SERVER_FOOD_UNITS)) {
        --client->player.inventory[0];
        if (client->player.inventory[0] == 0) {
            remove_client(client);
        } else {
            client->player.hunger = client->server->now;
        }
    }
}

static void player_commands(zappy_client_t *client)
{
    zappy_player_cmd_t *cmd = &client->player.cmds[0];
    unsigned long cmd_len = sizeof(zappy_player_cmd_t);

    if (cmd->pcmd != NULL && time_is_up(client->server
            , client->player.cmd_start, cmd->pcmd->time_limit)) {
        if (cmd->pcmd->func != NULL) {
            cmd->pcmd->func(client, cmd->data);
        }
        do {
            memcpy(client->player.cmds, &client->player.cmds[1], cmd_len * 9);
            memset(&client->player.cmds[9], 0, cmd_len);
            client->player.cmd_start = client->server->now;
        } while (cmd->pcmd != NULL
                && cmd->pcmd->start != NULL && !cmd->pcmd->start(client));
    }
}

static void update_players(zappy_server_t *server)
{
    zappy_client_t *client = NULL;

    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        client = &server->clients[i];
        if (!(client->sockfd < 0) && client->player.id != 0) {
            player_commands(client);
            player_hunger(client);
        }
    }
}

void game_loop(zappy_server_t *server)
{
    srand(time(NULL));
    if (clock_gettime(CLOCK_REALTIME, &server->now) != 0) {
        dprintf(2, "An internal error has occurred: %s\n", strerror(errno));
        return;
    }
    spawn_resources(server);
    while (!server->close && listen_sockets(server)) {
        update_players(server);
        if (time_is_up(server, server->resources
                , ZAPPY_SERVER_RESOURCES_UNITS)) {
            spawn_resources(server);
        }
    }
}
