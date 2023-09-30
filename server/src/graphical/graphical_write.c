/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_write.c
*/

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "zappy_server.h"

void graphical_write(zappy_server_t *server, const char *fmt, ...)
{
    zappy_client_t *client = NULL;
    va_list ap;

    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        client = &server->clients[i];
        if (!(client->sockfd < 0) && client->graphic) {
            va_start(ap, fmt);
            vdprintf(client->sockfd, fmt, ap);
            va_end(ap);
        }
    }
}
