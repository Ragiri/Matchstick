/*
** EPITECH PROJECT, 2018
** my_get_nbr
** File description:
** get int from a string
*/

#include <stdio.h>

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}

int my_atoi(char *nbr)
{
    int n = 1;
    int i = my_strlen(nbr) - 1;
    int res = 0;

    if (nbr[i] == '\n')
        i -= 1;
    while (i >= 0) {
        res = res + (n * (nbr[i] - 48));
        n = n * 10;
        i--;
    }
    return (res);
}
