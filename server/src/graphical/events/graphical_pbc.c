/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_pbc.c
*/

#include "zappy_server.h"

void graphical_pbc(zappy_server_t *server, zappy_player_t *player, char *br)
{
    graphical_write(server, "pbc %d %s\n"
            , player->id
            , br);
}
