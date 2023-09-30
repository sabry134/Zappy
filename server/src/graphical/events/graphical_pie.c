/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_pie.c
*/

#include "zappy_server.h"

void graphical_pie(zappy_server_t *server, zappy_player_t *player, int res)
{
    graphical_write(server, "pie %u %u %d\n"
            , player->x
            , player->y
            , res);
}
