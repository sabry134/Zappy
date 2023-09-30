/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** client.c
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "zappy_server.h"

void add_client(zappy_server_t *server, zappy_client_t *client, int sockfd
, struct sockaddr_in *addr_in)
{
    char *address = inet_ntoa(addr_in->sin_addr);

    memset(client, 0, sizeof(*client));
    client->sockfd = sockfd;
    memcpy(client->address, address, strlen(address));
    client->port = ntohs(addr_in->sin_port);
    client->server = server;
    dprintf(client->sockfd, "WELCOME\n");
    dprintf(1, "Client %s:%u connected!\n", client->address, client->port);
}

void remove_client(zappy_client_t *client)
{
    if (!(client->sockfd < 0)) {
        kill_player(client);
        close(client->sockfd);
        client->sockfd = -1;
        dprintf(1, "Client %s:%u disconnected!\n"
                , client->address, client->port);
    }
}
