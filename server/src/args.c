/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** args.c
*/

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include "zappy_server.h"

static void set_opt(zappy_server_t *server, int c, int num)
{
    if (c == 'p')
        server->port = num;
    if (c == 'x')
        server->width = num;
    if (c == 'y')
        server->height = num;
    if (c == 'c')
        server->clientsNb = num;
    if (c == 'f')
        server->freq = num;
}

static int check_arg(zappy_server_t *server, zappy_opt_t opts[5], int c)
{
    int res = is_number(optarg);
    int num = 0;
    zappy_opt_t *opt = NULL;

    if (res) {
        num = atoi(optarg);
    }
    for (int i = 0; i < 5; ++i) {
        opt = &opts[i];
        if (opt->c == c && !opt->func(res, num, c)) {
            return 0;
        }
    }
    set_opt(server, c, num);
    return 1;
}

int parse_args(int argc, char *argv[], zappy_server_t *server)
{
    zappy_opt_t opts[5] = {
        { 'p', check_opt_p },
        { 'x', check_opt_xy },
        { 'y', check_opt_xy },
        { 'c', check_opt_c },
        { 'f', check_opt_f }
    };
    int c = 0;

    opterr = 0;
    while ((c = getopt(argc, argv, "p:x:y:n:c:f:")) != -1) {
        if (c == '?') {
            dprintf(2, "Invalid argument: -%c\n", optopt);
            return 0;
        }
        if (optarg && !check_arg(server, opts, c)) {
            return 0;
        }
    }
    return 1;
}
