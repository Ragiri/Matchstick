/*
** EPITECH PROJECT, 2019
** main
** File description:
** matchstick
*/

#include "../include/my.h"
#include "../include/my_print.h"

int count_stick_line(char **map, int b)
{
    int i = 0;

    for (int c = 0; map[b][c]; c++) {
        if (map[b][c] == '|')
            i += 1;
    }
    return (i);
}

int matchstick(char **map, var_t *u)
{
    int c = 0;

    for (int k = 0; map[k]; k++)
        my_printf("%s", map[k]);
    my_printf("\n");
    while (1) {
        count_stick(map, &c);
        if (c == 0)
            return (0);
        my_printf("Your turn:\n");
        if (player_move_line(map, u) == 84)
            return (84);
        if (win_ai(map, u) == 2)
            return (2);
        if (win_player(map, u) == 1)
            return (1);
    }
}

int main(int ac, char **av, char **env)
{
    var_t k;
    char **map;

    if (!env[0])
        return (84);
    if (ac != 3)
        return (84);
    k.i = my_atoi(av[1]);
    k.n = my_atoi(av[2]);
    if (k.i < 1 || k.n < 1 || k.i >= 100)
        return (84);
    map = create_map(k.i);
    k.p = matchstick(map, &k);
    if (k.p == 1)
        return (1);
    if (k.p == 2)
        return (2);
    return (0);
}
