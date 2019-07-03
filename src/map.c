/*
** EPITECH PROJECT, 2019
** ez
** File description:
** vz
*/

#include "../include/my.h"
#include "../include/my_print.h"

int line(char *buff, var_t *u, char **map)
{
    for (int c = 0; buff[c] != '\n'; c++) {
        if (buff[c] > '9' || buff[c] < '0') {
            my_printf("invalid input (positive number expected)\n");
            return (player_move_line(map, u));
        }
    }
    if (u->b <= 0 || u->b > u->i) {
        my_printf("Error: this line is out of range\n");
        return (player_move_line(map, u));
    }
    return (0);
}

int match(char *buff, var_t *u, char **map)
{
    for (int c = 0; buff[c] != '\n'; c++) {
        if (buff[c] > '9' || buff[c] < '0') {
            my_printf("invalid input (positive number expected)\n");
            return (player_move_line(map, u));
        }
    }
    if (u->a <= 0) {
        my_printf("you have to remove at least one match\n");
        return (player_move_line(map, u));
    }
    if (u->a > u->n) {
        my_printf("you cannot remove more than %d matches per turn\n", u->n);
        return (player_move_line(map, u));
    }
    return (0);
}

int player_move_line(char **map, var_t *u)
{
    char *buff = malloc(sizeof(char) * 5);
    size_t nb = 20;

    my_printf("Line: ");
    if (getline(&buff, &nb, stdin) == -1)
        return (84);
    u->b = my_atoi(buff);
    line(buff, u, map);
    if (player_move_match(map, u) == 84)
        return (84);
    return (0);
}

int player_move_match(char **map, var_t *u)
{
    char *buff = malloc(sizeof(char) * 5);
    size_t nb = 20;
    int l = 0;

    l = count_stick_line(map, u->b);
    my_printf("Matches: ");
    if (getline(&buff, &nb, stdin) == -1)
        return (84);
    u->a = my_atoi(buff);
    if (l == 0 || l < u->a) {
        my_printf("Error: not enough matches on this line\n");
        return (player_move_line(map, u));
    }
    match(buff, u, map);
    return (0);
}
