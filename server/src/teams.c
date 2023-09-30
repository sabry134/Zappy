/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** teams.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zappy_server.h"

static zappy_team_t *create_team(char *team_name)
{
    zappy_team_t *team = malloc(sizeof(zappy_team_t));
    char *name = strdup(team_name);

    if (team != NULL && name != NULL) {
        memset(team, 0, sizeof(*team));
        team->name = name;
        if (strcmp(team_name, "GRAPHIC") != 0) {
            return team;
        } else {
            dprintf(2, "An internal error has occurred: GRAPHIC is reserved\n");
        }
    } else {
        dprintf(2, "An internal error has occurred: Unable to create a team\n");
    }
    free(team);
    free(name);
    return NULL;
}

static int create_default_teams(zappy_server_t *server)
{
    zappy_team_t **next_team = &server->teams;
    char team_name[6] = "Team ";

    for (int i = 0; i < 4; ++i) {
        team_name[4] = '1' + i;
        *next_team = create_team(team_name);
        if (*next_team == NULL) {
            return 0;
        }
        next_team = &(*next_team)->next;
    }
    return 1;
}

int parse_team_names(char *argv[], zappy_server_t *server)
{
    zappy_team_t **next_team = &server->teams;
    int i = 1;

    for (; argv[i] != NULL; ++i) {
        if (strcmp(argv[i], "-n") == 0) {
            ++i;
            break;
        }
    }
    for (; (argv[i] != NULL && argv[i][0] != '-'); ++i) {
        *next_team = create_team(argv[i]);
        if (*next_team == NULL) {
            return 0;
        }
        next_team = &(*next_team)->next;
    }
    if (server->teams == NULL) {
        return create_default_teams(server);
    }
    return 1;
}

zappy_team_t *get_team(zappy_server_t *server, char *team_name)
{
    zappy_team_t *next_team = server->teams;

    while (next_team != NULL) {
        if (strcmp(next_team->name, team_name) == 0) {
            return next_team;
        }
        next_team = next_team->next;
    }
    return NULL;
}

void free_teams(zappy_server_t *server)
{
    zappy_team_t *next_team = server->teams;
    zappy_team_t *team = NULL;

    while (next_team != NULL) {
        team = next_team;
        next_team = team->next;
        free_eggs(team);
        free(team->name);
        free(team);
    }
}
