/*
** EPITECH PROJECT, 2021
** main for tail
** File description:
** tail project
*/

#include "../include/my.h"
#include "../include/game_of_life.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int analyse(char **tab)
{
    int max = my_strlen(tab[0]);

    for (int i = 0; tab[i] != NULL; i++)
        if (my_strlen(tab[i]) != max)
            return (1);
    return 0;
}
