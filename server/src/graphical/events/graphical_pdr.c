/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_pdr.c
*/

#include "zappy_server.h"

void graphical_pdr(zappy_server_t *server, zappy_player_t *player, int i)
{
    graphical_write(server, "pdr %d %d\n"
            , player->id
            , i);
}
