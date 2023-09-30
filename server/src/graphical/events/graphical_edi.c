/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_edi.c
*/

#include "zappy_server.h"

void graphical_edi(zappy_server_t *server, zappy_egg_t *egg)
{
    graphical_write(server, "edi %d\n"
            , egg->id);
}
