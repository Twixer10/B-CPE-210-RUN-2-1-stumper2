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

char **my_tab_dup(char **tab)
{
    char **init = NULL;
    int lines = 0;

    for (; tab[lines] != NULL; lines++);
    init = malloc(sizeof(char *) * (lines + 1));
    for (lines = 0; tab[lines] != NULL; lines++)
        init[lines] = my_strdup(tab[lines]);
    init[lines] = NULL;
    return init;
}

void tab_free(char **tab)
{
    for (int lines = 0; tab[lines] != NULL; lines++)
        free(tab[lines]);
}

void iterate_file(char **tab, int ite)
{
    char **new = my_tab_dup(tab);

    for (int i = 0; i != ite; i++){
        add_deceased(tab, new);
        tab_free(tab);
        tab = my_tab_dup(new);
    }
    for (int lines = 0; new[lines] != NULL; lines++){
        my_putstr(new[lines]);
        my_putchar('\n');
    }
    tab_free(tab);
    tab_free(new);
    free(tab);
    free(new);
}

int main(int ac, char **av)
{
    char *str = NULL;
    char **tab = NULL;

    if (ac == 3) {
        str = load_file_in_mem(av[1]);
        if (str != NULL && my_str_isnum_nm(av[2]) != 84){
            tab = str_to_wa(str,'\n');
            iterate_file(tab, my_getnbr(av[2]));
        }
        else
            return 84;
    }
    else
        return 84;
    return 0;
}
