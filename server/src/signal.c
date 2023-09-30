/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** signal.c
*/

#include <stddef.h>
#include <signal.h>
#include <sys/signalfd.h>
#include "zappy_server.h"

void setup_signal(zappy_server_t *server)
{
    sigset_t mask;

    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);
    sigprocmask(SIG_BLOCK, &mask, NULL);
    server->signalfd = signalfd(-1, &mask, 0);
}
