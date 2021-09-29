/*
** EPITECH PROJECT, 2021
** tail.h
** File description:
** include file for tail
*/

#ifndef GAME_OF_LIFE_H_
#define GAME_OF_LIFE_H_

void add_deceased(char **old, char **new);
int analyse(char **tab);
int check_str(char *str, char *needles);

#endif
