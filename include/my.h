/*
** EPITECH PROJECT, 2019
** vz
** File description:
** bz
*/

#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef MY_H_
#define MY_H_

typedef struct variable_s
{
    int i;
    int n;
    int a;
    int b;
    int p;
}var_t;

int win_player(char**, var_t*);
int win_ai(char**, var_t*);
int count_stick_line(char**, int);
int my_atoi(char*);
int my_strlen(char*);
int player_move_line(char**, var_t*);
int player_move_match(char**, var_t*);
int line(char*, var_t*, char**);
int match(char*, var_t*, char**);
int count_stick(char**, int*);
char **create_map(int);
char **map_after_turn(char**, var_t*);
char **ai_move(char**, var_t*);

#endif
