/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** server.c
*/

#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "zappy_server.h"

static int create_socket(zappy_server_t *server)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr_in = {
        .sin_family = AF_INET,
        .sin_port = htons(server->port),
        .sin_addr = { .s_addr = INADDR_ANY }
    };

    if (sockfd < 0) {
        return 0;
    }
    if (bind(sockfd, (struct sockaddr*)&addr_in, sizeof(addr_in)) != 0) {
        close(sockfd);
        return 0;
    }
    if (listen(sockfd, ZAPPY_SERVER_MAX_CLIENTS) != 0) {
        close(sockfd);
        return 0;
    }
    server->sockfd = sockfd;
    return 1;
}

static int display_port(zappy_server_t *server)
{
    struct sockaddr_in addr_in;
    socklen_t socklen = sizeof(addr_in);
    int sockfd = server->sockfd;

    if (getsockname(sockfd, (struct sockaddr*)&addr_in, &socklen) == 0) {
        dprintf(1, "Listening on port : %d\n", ntohs(addr_in.sin_port));
        return 1;
    }
    return 0;
}

int start_server(zappy_server_t *server)
{
    if (create_socket(server) && display_port(server)) {
        return 1;
    }
    dprintf(2, "An internal error has occurred: %s\n", strerror(errno));
    return 0;
}

void stop_server(zappy_server_t *server)
{
    if (!(server->sockfd < 0)) {
        close(server->sockfd);
        server->sockfd = -1;
    }
}
