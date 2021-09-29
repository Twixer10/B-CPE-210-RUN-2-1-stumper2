/*
** EPITECH PROJECT, 2021
** gol
** File description:
** gol
*/

#include "../include/my.h"
#include "../include/game_of_life.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void check_deceased(int n_cell[8], char **old, int i, int e)
{
    int cln[8] = {0};

    cln[0] = (i > 0 && e > 0 && old[i - 1][e - 1] == 'X') ? 1 : 0;
    cln[1] = (e > 0 && old[i][e - 1] == 'X') ? 1 : 0;
    cln[2] = (old[i + 1] != NULL && e > 0 && old[i + 1][e - 1] == 'X') ? 1 : 0;
    cln[3] = (i > 0 && old[i - 1][e] == 'X') ? 1 : 0;
    cln[4] = (old[i + 1] != NULL && old[i + 1][e] == 'X') ? 1 : 0;
    cln[5] = (i > 0 && old [i - 1][e + 1] != '\0'
              && old[i - 1][e + 1] == 'X') ? 1 : 0;
    cln[6] = (old [i][e + 1] != '\0' && old[i][e + 1] == 'X') ? 1 : 0;
    cln[7] = (old[i + 1] != NULL && old [i + 1][e + 1] != '\0'
              && old[i + 1][e + 1] == 'X') ? 1 : 0;

    for (int i = 0; i != 8; i++)
        n_cell[i] = cln[i];
}

int get_sum(int n_cell[8])
{
    int sum = 0;

    for (int i = 0; i != 8; i++)
        sum += n_cell[i];
    return sum;
}

void add_deceased(char **old, char **new)
{
    int n_cell[8] = {0};
    int sum = 0;
    int e = 0;

    for (int i = 0; old[i] != NULL; i++) {
        for (e = 0; old[i][e] != '\0'; e++) {
            if (old[i][e] == 'X' || old[i][e] == '.') {
                check_deceased(n_cell, old, i, e);
                sum = get_sum(n_cell);
                new[i][e] = (sum == 3) ? 'X' : new[i][e];
                new[i][e] = (sum < 2 || sum > 3) ? '.' : new[i][e];
            }
        }
    }
}
