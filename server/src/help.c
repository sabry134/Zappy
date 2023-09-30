/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** help.c
*/

#include <stdio.h>
#include <string.h>

static void display_help(void)
{
    dprintf(1,  "USAGE:\t./zappy_server -p port -x width -y height"
                " -n name1 name2 ... -c clientsNb -f freq\n"
                "\tport\t\tis the port number\n"
                "\twidth\t\tis the width of the world\n"
                "\theight\t\tis the height of the world\n"
                "\tnameX\t\tis the name of the team X\n"
                "\tclientsNb\tis the number of authorized clients per team\n"
                "\tfreq\t\tis the reciprocal of time unit for execution of"
                " actions\n");
}

int check_help(int argc, char *argv[])
{
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-help") == 0) {
            display_help();
            return 1;
        }
    }
    return 0;
}
