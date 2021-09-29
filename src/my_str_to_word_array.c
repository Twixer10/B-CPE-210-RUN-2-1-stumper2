/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** str_to_word_array
*/

#include "../include/my.h"
#include <stdlib.h>
#include <unistd.h>

char *add_in_str(char *str, char c)
{
    char *to_ret = malloc(sizeof(char) * (my_strlen(str) + 2));
    int i = 0;

    if (str){
        for (;str[i]; i += 1)
            to_ret[i] = str[i];
        free(str);
    }
    to_ret[i++] = c;
    to_ret[i] = '\0';
    return to_ret;
}

int my_str_seplen(char *str, char c)
{
    int i = 0;

    for (i = 0; str[i] != '\0' && str[i] != c; i++);
    return i + 1;
}

int count_words(char *str, char c)
{
    int i = 0;

    for (i = 0; str && str[i] != '\0'; i++)
        i += (str[i] == c) ? 1 : 0;
    return i + 1;
}

char **str_to_wa(char *str, char sep)
{
    char **tab = NULL;
    int e = 0;
    int j = 0;

    if (str == NULL)
        return NULL;
    tab = malloc(sizeof(char *) * (count_words(str, sep) + 1));
    for (int i = 0; str[i] != '\0'; i++, j++) {
        tab[j] = malloc(sizeof(char) * (my_str_seplen(str + i, sep)));
        for (e = 0; str[i] && str[i] != sep; i++, e++)
            tab[j][e] = str[i];
        tab[j][e] = '\0';
        if (str[i] == '\0'){
            j++;
            break;
        }
    }
    tab[j] = NULL;
    return tab;
}
