/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** time.c
*/

#include <time.h>
#include "zappy_server.h"

static struct timespec get_end_time(struct timespec ts, double time_limit
, int freq)
{
    double duration = time_limit / freq;
    time_t sec = duration;

    ts.tv_sec += sec;
    ts.tv_nsec += (duration - sec) * 1000000000;
    if (ts.tv_nsec >= 1000000000) {
        ++ts.tv_sec;
        ts.tv_nsec -= 1000000000;
    }
    return ts;
}

int time_is_up(zappy_server_t *server, struct timespec ts, double time_limit)
{
    struct timespec *now = &server->now;
    struct timespec end = get_end_time(ts, time_limit, server->freq);

    return (now->tv_sec > end.tv_sec)
            || (now->tv_sec == end.tv_sec && now->tv_nsec >= end.tv_nsec);
}

struct timeval get_remaining_time(zappy_server_t *server, struct timespec ts
, double time_limit)
{
    struct timespec *now = &server->now;
    struct timespec end = get_end_time(ts, time_limit, server->freq);
    struct timeval remaining;

    remaining.tv_sec = end.tv_sec - now->tv_sec;
    remaining.tv_usec = (end.tv_nsec - now->tv_nsec) / 1000;
    if (remaining.tv_usec < 0) {
        --remaining.tv_sec;
        remaining.tv_usec += 1000000;
    }
    return remaining;
}
