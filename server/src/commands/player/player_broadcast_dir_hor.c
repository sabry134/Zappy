/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** player_broadcast_dir_hor.c
*/

#include <stdio.h>
#include "zappy_server.h"

void print_direction_nord(zappy_client_t *cli, int x, int y)
{
    if (x == 0 && y > 0)
        dprintf(cli->sockfd, "7, ");
    if (x == 0 && y < 0)
        dprintf(cli->sockfd, "3, ");
    if (x > 0 && y == 0)
        dprintf(cli->sockfd, "5, ");
    if (x < 0 && y == 0)
        dprintf(cli->sockfd, "1, ");
    if (x > 0 && y > 0)
        dprintf(cli->sockfd, "6, ");
    if (x < 0 && y < 0)
        dprintf(cli->sockfd, "2, ");
    if (x > 0 && y < 0)
        dprintf(cli->sockfd, "4, ");
    if (x < 0 && y > 0)
        dprintf(cli->sockfd, "8, ");
}

void print_direction_east(zappy_client_t *cli, int x, int y)
{
    if (x == 0 && y > 0)
        dprintf(cli->sockfd, "1, ");
    if (x == 0 && y < 0)
        dprintf(cli->sockfd, "5, ");
    if (x > 0 && y == 0)
        dprintf(cli->sockfd, "7, ");
    if (x < 0 && y == 0)
        dprintf(cli->sockfd, "3, ");
    if (x > 0 && y > 0)
        dprintf(cli->sockfd, "8, ");
    if (x < 0 && y < 0)
        dprintf(cli->sockfd, "4, ");
    if (x > 0 && y < 0)
        dprintf(cli->sockfd, "6, ");
    if (x < 0 && y > 0)
        dprintf(cli->sockfd, "2, ");
}

void print_direction_sud(zappy_client_t *cli, int x, int y)
{
    if (x == 0 && y > 0)
        dprintf(cli->sockfd, "3, ");
    if (x == 0 && y < 0)
        dprintf(cli->sockfd, "7, ");
    if (x > 0 && y == 0)
        dprintf(cli->sockfd, "1, ");
    if (x < 0 && y == 0)
        dprintf(cli->sockfd, "5, ");
    if (x > 0 && y > 0)
        dprintf(cli->sockfd, "2, ");
    if (x < 0 && y < 0)
        dprintf(cli->sockfd, "6, ");
    if (x > 0 && y < 0)
        dprintf(cli->sockfd, "8, ");
    if (x < 0 && y > 0)
        dprintf(cli->sockfd, "4, ");
}

void print_direction_west(zappy_client_t *cli, int x, int y)
{
    if (x == 0 && y > 0)
        dprintf(cli->sockfd, "5, ");
    if (x == 0 && y < 0)
        dprintf(cli->sockfd, "1, ");
    if (x > 0 && y == 0)
        dprintf(cli->sockfd, "3, ");
    if (x < 0 && y == 0)
        dprintf(cli->sockfd, "7, ");
    if (x > 0 && y > 0)
        dprintf(cli->sockfd, "4, ");
    if (x < 0 && y < 0)
        dprintf(cli->sockfd, "8, ");
    if (x > 0 && y < 0)
        dprintf(cli->sockfd, "2, ");
    if (x < 0 && y > 0)
        dprintf(cli->sockfd, "6, ");
}
