/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** client_read.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "zappy_server.h"

static void player_join_team(zappy_client_t *client, zappy_team_t *team
, zappy_egg_t *egg)
{
    static int player_id = 0;
    zappy_server_t *server = client->server;

    client->player.id = ++player_id;
    client->player.x = rand() % server->width;
    client->player.y = rand() % server->height;
    client->player.rot = (rand() % 4) + 1;
    client->player.lvl = 1;
    client->player.inventory[0] = 10;
    client->player.team = team;
    dprintf(client->sockfd, "%d\n", team->slot);
    dprintf(client->sockfd, "%d %d\n", server->width, server->height);
    if (egg != NULL) {
        client->player.x = egg->x;
        client->player.y = egg->y;
        graphical_ebo(client->server, egg);
        free(egg);
    }
    graphical_pnw(client->server, &client->player);
}

static void register_team(zappy_client_t* client, char* data)
{
    zappy_server_t *server = client->server;
    zappy_team_t *team = get_team(server, data);
    zappy_egg_t *egg = NULL;

    if (team != NULL
            && (get_nb_players_team(server, team) < server->clientsNb
            || (egg = get_random_egg(team)) != NULL)) {
        player_join_team(client, team, egg);
    } else if (strcmp(data, "GRAPHIC") == 0) {
        client->graphic = 1;
        graphical_join(client);
    } else {
        dprintf(client->sockfd, "ko\n");
    }
}

static void parse_cmd(zappy_client_t* client, char* data)
{
    if (client->graphic) {
        commands_graphical(client, data);
    } else if (client->player.id != 0) {
        commands_player(client, data);
    } else {
        register_team(client, data);
    }
}

static void parse_read(zappy_client_t* client)
{
    static char* sep = "\n";
    char* buffer = client->buffer;
    char* pos = NULL;

    while ((pos = strstr(buffer, sep)) != NULL) {
        pos[0] = '\0';
        if (strlen(buffer) > 0) {
            parse_cmd(client, buffer);
        }
        buffer = pos + strlen(sep);
    }
    client->pending = strlen(buffer);
    if (client->pending > 0) {
        memcpy(client->buffer, buffer, client->pending);
    }
}

void read_client(zappy_client_t* client)
{
    ssize_t bytesread = 0;
    size_t bytes = ZAPPY_SERVER_BUFFER_SIZE - client->pending - 1;

    bytesread = read(client->sockfd, client->buffer + client->pending, bytes);
    if (bytesread > 0) {
        client->buffer[bytesread + client->pending] = '\0';
        parse_read(client);
    } else {
        client->sockclose = 1;
        remove_client(client);
    }
}
