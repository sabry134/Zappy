/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** main.c
*/

#include <string.h>
#include "zappy_server.h"

static void zappy_free(zappy_server_t *server)
{
    free_teams(server);
    stop_server(server);
    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        remove_client(&server->clients[i]);
    }
}

static void zappy_init_player_commands(zappy_server_t *server)
{
    zappy_pcmd_t *pcmds = server->player_commands;

    pcmds[0] = (zappy_pcmd_t){ "Broadcast", 7, broadcast, NULL };
    pcmds[1] = (zappy_pcmd_t){ "Connect_nbr", 0, player_connect_nbr, NULL };
    pcmds[2] = (zappy_pcmd_t){ "Eject", 7, player_eject, NULL };
    pcmds[3] = (zappy_pcmd_t){ "Fork", 42, player_fork, egg_laying };
    pcmds[4] = (zappy_pcmd_t){ "Forward", 7, player_forward, NULL };
    pcmds[5] = (zappy_pcmd_t){ "Incantation"
            , 300, player_incantation, can_elevation_start };
    pcmds[6] = (zappy_pcmd_t){ "Inventory", 1, player_inventory, NULL };
    pcmds[7] = (zappy_pcmd_t){ "Left", 7, player_left, NULL };
    pcmds[8] = (zappy_pcmd_t){ "Look", 7, player_look, NULL };
    pcmds[9] = (zappy_pcmd_t){ "Right", 7, player_right, NULL };
    pcmds[10] = (zappy_pcmd_t){ "Set", 7, player_set, NULL };
    pcmds[11] = (zappy_pcmd_t){ "Take", 7, player_take, NULL };
    server->incantation_wait = (zappy_pcmd_t){ "\0", 300, NULL, NULL };
}

static void zappy_init_graphical_commands(zappy_server_t *server)
{
    server->graphical_commands[0] = (zappy_gcmd_t){ "bct", graphical_bct };
    server->graphical_commands[1] = (zappy_gcmd_t){ "mct", graphical_mct };
    server->graphical_commands[2] = (zappy_gcmd_t){ "msz", graphical_msz };
    server->graphical_commands[3] = (zappy_gcmd_t){ "pin", graphical_pin };
    server->graphical_commands[4] = (zappy_gcmd_t){ "plv", graphical_plv };
    server->graphical_commands[5] = (zappy_gcmd_t){ "ppo", graphical_ppo };
    server->graphical_commands[6] = (zappy_gcmd_t){ "sgt", graphical_sgt };
    server->graphical_commands[7] = (zappy_gcmd_t){ "sst", graphical_sst };
    server->graphical_commands[8] = (zappy_gcmd_t){ "tna", graphical_tna };
}

static int zappy_init(int argc, char *argv[], zappy_server_t *server)
{
    char *argvcpy[argc + 1];

    memcpy(argvcpy, argv, sizeof(char*) * (argc + 1));
    memset(server, 0, sizeof(*server));
    server->port = 4242;
    server->width = 10;
    server->height = 10;
    server->clientsNb = 3;
    server->freq = 100;
    server->sockfd = -1;
    server->signalfd = -1;
    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        server->clients[i].sockfd = -1;
    }
    zappy_init_graphical_commands(server);
    zappy_init_player_commands(server);
    if (!parse_args(argc, argv, server) || !parse_team_names(argvcpy, server)) {
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    zappy_server_t server;
    int res = 0;

    if (check_help(argc, argv)) {
        return 0;
    }
    res = zappy_init(argc, argv, &server);
    if (res) {
        res = start_server(&server);
        if (res) {
            setup_signal(&server);
            game_loop(&server);
        }
    }
    zappy_free(&server);
    return (res ? 0 : 84);
}
