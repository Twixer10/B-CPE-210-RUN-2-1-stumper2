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

int check_str(char *str, char *needles)
{
    int check = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        check = 0;
        for (int e = 0; needles[e] != '\0'; e++)
            if (str[i] == needles[e])
                check = 1;
        if (check == 0)
            return 1;
    }
    return 0;
}
