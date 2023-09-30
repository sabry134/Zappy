/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** player.c
*/

#include <stdio.h>
#include <string.h>
#include "zappy_server.h"

zappy_player_t *get_player_by_id(zappy_server_t *server, int id)
{
    zappy_client_t *client = NULL;

    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        client = &server->clients[i];
        if (client->player.id != 0 && client->player.id == id) {
            return &client->player;
        }
    }
    return NULL;
}

void add_player_command(zappy_client_t* client, zappy_pcmd_t *pcmd, char *data)
{
    int i = 0;
    int data_len = data != NULL ? strlen(data) : 0;

    if (pcmd->start != NULL && !pcmd->start(client)) {
        return;
    }
    data_len = (data_len >= 64) ? 63 : data_len;
    for (; i < 10; ++i) {
        if (client->player.cmds[i].pcmd == NULL) {
            client->player.cmds[i].pcmd = pcmd;
            memset(client->player.cmds[i].data, 0, 64);
            memcpy(client->player.cmds[i].data, data, data_len);
            break;
        }
    }
    if (i == 0) {
        client->player.cmd_start = client->server->now;
    }
}

void kill_player(zappy_client_t *client)
{
    if (client->player.id != 0) {
        if (!client->sockclose) {
            dprintf(client->sockfd, "dead\n");
        }
        if (client->player.elevation
                && client->player.cmds[0].pcmd != NULL
                && client->player.cmds[0].pcmd->func == player_incantation) {
            graphical_pie(client->server, &client->player, 0);
        }
        graphical_pdi(client->server, &client->player);
        memset(&client->player, 0, sizeof(client->player));
    }
}

int get_nb_players_team(zappy_server_t *server, zappy_team_t *team)
{
    zappy_client_t *client = NULL;
    int nb = 0;

    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        client = &server->clients[i];
        if (!(client->sockfd < 0)
                && client->player.id != 0
                && client->player.team == team) {
            ++nb;
        }
    }
    return nb;
}
