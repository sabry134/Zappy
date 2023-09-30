/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** resources.c
*/

#include <stdlib.h>
#include <string.h>
#include "zappy_server.h"

static int *get_random_tile(zappy_server_t *server)
{
    int y = rand() % server->height;
    int x = rand() % server->width;

    return server->map[y][x];
}

static void balance_resource(zappy_server_t *server, int *resources, int i)
{
    for (int y = 0; y < server->height; ++y) {
        for (int x = 0; x < server->width; ++x) {
            resources[i] -= server->map[y][x][i];
        }
    }
}

void spawn_resources(zappy_server_t *server)
{
    int resources[7] = {
        server->width * server->height * 0.5f,
        server->width * server->height * 0.3f,
        server->width * server->height * 0.15f,
        server->width * server->height * 0.1f,
        server->width * server->height * 0.1f,
        server->width * server->height * 0.08f,
        server->width * server->height * 0.05f
    };
    int *tile = NULL;

    for (int i = 0; i < 7; ++i) {
        balance_resource(server, resources, i);
        while (resources[i] > 0) {
            tile = get_random_tile(server);
            ++tile[i];
            --resources[i];
        }
    }
    server->resources = server->now;
}

int get_resource_index(const char *str)
{
    if (strcmp(str, "food") == 0)
        return 0;
    if (strcmp(str, "linemate") == 0)
        return 1;
    if (strcmp(str, "deraumere") == 0)
        return 2;
    if (strcmp(str, "sibur") == 0)
        return 3;
    if (strcmp(str, "mendiane") == 0)
        return 4;
    if (strcmp(str, "phiras") == 0)
        return 5;
    if (strcmp(str, "thystame") == 0)
        return 6;
    return -1;
}

char *get_resource_name(int i)
{
    if (i == 0)
        return "food";
    if (i == 1)
        return "linemate";
    if (i == 2)
        return "deraumere";
    if (i == 3)
        return "sibur";
    if (i == 4)
        return "mendiane";
    if (i == 5)
        return "phiras";
    if (i == 6)
        return "thystame";
    return "";
}
