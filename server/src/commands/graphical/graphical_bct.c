/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_bct.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zappy_server.h"

int tile_content(zappy_client_t *client, int x, int y)
{
    int width = client->server->width;
    int height = client->server->height;
    int *tile = NULL;

    if (x < 0 || y < 0 || x >= width || y >= height) {
        return 0;
    }
    tile = client->server->map[y][x];
    dprintf(client->sockfd
            , "bct %d %d %d %d %d %d %d %d %d\n"
            , x
            , y
            , tile[0]
            , tile[1]
            , tile[2]
            , tile[3]
            , tile[4]
            , tile[5]
            , tile[6]);
    return 1;
}

static int parse_bct(char *data, char **x, char **y)
{
    *x = data;
    data = strstr(data, " ");
    if (data != NULL) {
        data[0] = '\0';
        ++data;
        *y = data;
        if (strstr(data, " ") == NULL) {
            return 1;
        }
    }
    return 0;
}

void graphical_bct(zappy_client_t *client, char *data)
{
    char *x = NULL;
    char *y = NULL;

    if (!(data
            && parse_bct(data, &x, &y)
            && is_number(x)
            && is_number(y)
            && tile_content(client, atoi(x), atoi(y)))) {
        dprintf(client->sockfd, "sbp\n");
    }
}
