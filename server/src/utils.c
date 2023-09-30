/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** utils.c
*/

#include <ctype.h>
#include <string.h>

int is_number(char* str)
{
    if (str == NULL || strlen(str) == 0) {
        return 0;
    }
    for (int i = 0; str[i] != '\0'; ++i) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int modulo(int num, int div)
{
    return (num % div) + (num < 0 ? div : 0);
}
