/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_seg.c
*/

#include "zappy_server.h"

void graphical_seg(zappy_server_t *server, char *team_name)
{
    graphical_write(server, "seg %s\n"
            , team_name);
    server->close = 1;
}
