/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** server_listen.c
*/

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/select.h>
#include <time.h>
#include "zappy_server.h"

static void set_client_fds(zappy_server_t *server, fd_set *readfds, int *maxfd)
{
    static zappy_client_t *client = NULL;

    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        client = &server->clients[i];
        if (!(client->sockfd < 0)) {
            FD_SET(client->sockfd, readfds);
            *maxfd = (client->sockfd > *maxfd) ? client->sockfd : *maxfd;
        }
    }
}

static void init_select(zappy_server_t *server, fd_set *readfds, int *maxfd)
{
    FD_ZERO(readfds);
    FD_SET(server->sockfd, readfds);
    *maxfd = server->sockfd;
    if (server->signalfd != -1) {
        FD_SET(server->signalfd, readfds);
        if (server->signalfd > *maxfd) {
            *maxfd = server->signalfd;
        }
    }
    set_client_fds(server, readfds, maxfd);
}

static void find_timeout(zappy_server_t *server, struct timeval **timeout_ptr
, struct timespec ts, double time_limit)
{
    static struct timeval timeout;
    struct timeval remaining = get_remaining_time(server, ts, time_limit);

    if ((*timeout_ptr == NULL
            || remaining.tv_sec < timeout.tv_sec
            || (remaining.tv_sec == timeout.tv_sec
            && remaining.tv_usec < timeout.tv_usec))
            && ((remaining.tv_sec > 0 && remaining.tv_usec >= 0)
            || (remaining.tv_sec == 0 && remaining.tv_usec > 0))) {
        timeout.tv_sec = remaining.tv_sec;
        timeout.tv_usec = remaining.tv_usec;
        *timeout_ptr = &timeout;
    }
}

static void next_timeout(zappy_server_t *server, struct timeval **timeout_ptr)
{
    zappy_client_t *client = NULL;
    zappy_player_t *player = NULL;
    zappy_player_cmd_t *cmd = NULL;
    int time_limit = 0;

    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        client = &server->clients[i];
        player = &client->player;
        cmd = &player->cmds[0];
        if (client->sockfd < 0 || player->id == 0)
            continue;
        if (cmd->pcmd != NULL) {
            time_limit = cmd->pcmd->time_limit;
            find_timeout(server, timeout_ptr, player->cmd_start, time_limit);
        }
        time_limit = ZAPPY_SERVER_FOOD_UNITS;
        find_timeout(server, timeout_ptr, player->hunger, time_limit);
    }
    time_limit = ZAPPY_SERVER_RESOURCES_UNITS;
    find_timeout(server, timeout_ptr, server->resources, time_limit);
}

int listen_sockets(zappy_server_t *server)
{
    static fd_set readfds;
    static int maxfd = 0;
    static int fds = 0;
    struct timeval *timeout_ptr = NULL;

    init_select(server, &readfds, &maxfd);
    next_timeout(server, &timeout_ptr);
    fds = select(maxfd + 1, &readfds, NULL, NULL, timeout_ptr);
    if (clock_gettime(CLOCK_REALTIME, &server->now) != 0) {
        dprintf(2, "An internal error has occurred: %s\n", strerror(errno));
        return -1;
    }
    if (fds > 0) {
        return read_select(server, &readfds);
    }
    if (fds < 0) {
        dprintf(2, "An internal error has occurred: %s\n", strerror(errno));
    }
    return !(fds < 0);
}
