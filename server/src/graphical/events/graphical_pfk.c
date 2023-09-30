/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_pfk.c
*/

#include "zappy_server.h"

void graphical_pfk(zappy_server_t *server, zappy_player_t *player)
{
    graphical_write(server, "pfk %d\n"
            , player->id);
}
