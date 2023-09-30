/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_pgt.c
*/

#include "zappy_server.h"

void graphical_pgt(zappy_server_t *server, zappy_player_t *player, int i)
{
    graphical_write(server, "pgt %d %d\n"
            , player->id
            , i);
}
