/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** egg.c
*/

#include <stdlib.h>
#include "zappy_server.h"

zappy_egg_t *spawn_egg(zappy_client_t *client)
{
    static int egg_id = 0;
    zappy_egg_t **egg = &client->player.team->eggs;

    while (*egg != NULL) {
        egg = &(*egg)->next;
    }
    *egg = malloc(sizeof(zappy_egg_t));
    if (*egg == NULL) {
        return NULL;
    }
    (*egg)->id = ++egg_id;
    (*egg)->player_id = client->player.id;
    (*egg)->x = client->player.x;
    (*egg)->y = client->player.y;
    (*egg)->next = NULL;
    ++client->player.team->slot;
    return (*egg);
}

zappy_egg_t* get_random_egg(zappy_team_t *team)
{
    zappy_egg_t **egg = &team->eggs;
    zappy_egg_t *res = NULL;
    int i = 0;

    if (team->slot > 0) {
        i = rand() % team->slot;
        while (i > 0) {
            egg = &(*egg)->next;
            --i;
        }
        res = *egg;
        *egg = (*egg)->next;
        --team->slot;
    }
    return res;
}

void free_eggs(zappy_team_t *team)
{
    zappy_egg_t *next_egg = team->eggs;
    zappy_egg_t *egg = NULL;

    while (next_egg != NULL) {
        egg = next_egg;
        next_egg = egg->next;
        free(egg);
    }
}
