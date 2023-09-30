/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** server_read.c
*/

#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>
#include "zappy_server.h"

static int accept_client(zappy_server_t *server)
{
    struct sockaddr_in addr_in;
    socklen_t addrlen = sizeof(addr_in);
    int sockfd = accept(server->sockfd, (struct sockaddr*)&addr_in, &addrlen);

    if (sockfd < 0) {
        return 0;
    }
    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        if (server->clients[i].sockfd < 0) {
            add_client(server, &server->clients[i], sockfd, &addr_in);
            return 1;
        }
    }
    close(sockfd);
    dprintf(1, "Unable to accept new client: Server is full\n");
    return 1;
}

int read_select(zappy_server_t *server, fd_set *readfds)
{
    static zappy_client_t *client = NULL;

    if (FD_ISSET(server->sockfd, readfds)) {
        if (!accept_client(server)) {
            return 0;
        }
    }
    if (server->signalfd != -1 && FD_ISSET(server->signalfd, readfds)) {
        return 0;
    }
    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        client = &server->clients[i];
        if (!(client->sockfd < 0) && FD_ISSET(client->sockfd, readfds)) {
            read_client(client);
        }
    }
    return 1;
}
