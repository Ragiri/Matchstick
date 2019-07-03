/*
** EPITECH PROJECT, 2019
** ia
** File description:
** vez
*/

#include "../include/my.h"
#include "../include/my_print.h"

int count_stick(char **str, int *a)
{
    int b = 0;

    for (int n = 0; str[n]; n++) {
        for (int i = 0; str[n][i]; i++) {
            if (str[n][i] == '|')
                b += 1;
        }
    }
    *a = b;
    return (*a);
}

void last_stick(char *str, int *i)
{
    for (int n = 0; str[n]; n++) {
        if (str[n] == '|')
            *i = n;
    }
}

char **map_after_turn(char **map, var_t *u)
{
    int m = 0;

    for (int i = 0; map[i]; i++) {
        if (i == u->b) {
            last_stick(map[i], &m);
            for (int c = 0; c < u->a; c++)
                map[i][m - c] = ' ';
        }
    }
    my_printf("Player removed %d match(es) from line %d\n", u->a, u->b);
    for (int l = 0; map[l]; l++)
        my_printf("%s\n", map[l]);
    return (map);
}

void val(char **map, int *a, int *b, var_t *u)
{
    int l = count_stick_line(map, *a);

    if (l % 2 == 0) {
        while (*b % 2 == 0 || *b > l || *b == 0 || *a == 0) {
            *b = rand() % u->n;
            *a = rand() % u->i + 1;
            l = count_stick_line(map, *a);
        }
    } else if (l % 2 == 1) {
        while (*a == 0 || *b % 2 == 1 || *b == 0 || *b > l) {
            *b = rand() % u->n + 1;
            *a = rand() % u->i + 1;
            l = count_stick_line(map, *a);
        }
    }
}

char **ai_move(char **map, var_t *u)
{
    int a = 0;
    int b = 0;
    int m = 0;

    val(map, &a, &b, u);
    my_printf("AI's turn...\n");
    for (int d = 0; map[d]; d++) {
        if (d == a) {
            last_stick(map[d], &m);
            for (int c = 0; c < b; c++)
                map[d][m - c] = ' ';
        }
    }
    my_printf("AI removed %d match(es) from line %d\n", b, a);
    for (int l = 0; map[l]; l++)
        my_printf("%s\n", map[l]);
    return (map);
}
