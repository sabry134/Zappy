/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** args_handling.c
*/

#include <stdio.h>
#include "zappy_server.h"

int check_opt_p(int is_number, int num, int c)
{
    if (!is_number || num < 0) {
        dprintf(2, "Arguments -%c only accepts valid ports\n", c);
        return 0;
    }
    return 1;
}

int check_opt_xy(int is_number, int num, int c)
{
    if (!is_number || num < 10 || num > 30) {
        dprintf(2,  "Arguments -%c only accepts integer values"
                    " between 10 and 30\n", c);
        return 0;
    }
    return 1;
}

int check_opt_c(int is_number, int num, int c)
{
    if (!is_number || num < 1) {
        dprintf(2,  "Arguments -%c only accepts integer values"
                    " greater or equal to 1\n", c);
        return 0;
    }
    return 1;
}

int check_opt_f(int is_number, int num, int c)
{
    if (!is_number || num < 2 || num > 1000) {
        dprintf(2,  "Arguments -%c only accepts integer values"
                    " between 2 and 10000\n", c);
        return 0;
    }
    return 1;
}
