/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_ebo.c
*/

#include "zappy_server.h"

void graphical_ebo(zappy_server_t *server, zappy_egg_t *egg)
{
    graphical_write(server, "ebo %d\n"
            , egg->id);
}
