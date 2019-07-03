/*
** EPITECH PROJECT, 2019
** create map
** File description:
** matchstick
*/

#include "../include/my.h"
#include "../include/my_print.h"


void create_map_second(char **map, int e, int x, int k)
{
    for (int g = 0; g < e - 1; g++) {
        if (g == 0 || g == e - 2)
            map[k][g] = '*';
        else if (g == x - (k - 1)) {
            for (int f = x - (k - 1); f < x + k; f++) {
                map[k][g] = '|';
                g += 1;
            }
            g -= 1;
        } else
            map[k][g] = ' ';
    }
}

char **create_map(int i)
{
    int e = i + i + 2;
    int d = i + 2;
    int x = ((i + i - 2) / 2)+ 1;
    char **map = malloc(sizeof(char*) * (d + 1));

    for (int l = 0; l <= d; l++)
        map[l] = malloc(sizeof(char) * e);
    for (int h = 0; h < e - 1; h++)
        map[0][h] = '*';
    for (int j = 0; j < e - 1; j++)
        map[d - 1][j] = '*';
    map[d] = NULL;
    for (int k = 1; k <= i; k++)
        create_map_second(map, e, x, k);
    return (map);
}

int win_player(char **map, var_t *u)
{
    int l = 0;

    map = ai_move(map, u);
    l = count_stick(map, &l);
    if (l == 0) {
        my_printf("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    my_printf("\n");
    return (0);
}

int win_ai(char **map, var_t *u)
{
    int l = 0;

    map = map_after_turn(map, u);
    l = count_stick(map, &l);
    if (l == 0) {
        my_printf("You lost, too bad...\n");
        return (2);
    }
    my_printf("\n");
    return (0);
}
