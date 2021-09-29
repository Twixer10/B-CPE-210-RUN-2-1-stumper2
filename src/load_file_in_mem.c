/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** load_file_in_mem
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "../include/my.h"

#define BUFF_SIZE (ssize_t){40000000}

char *load_file_in_mem(char const *filepath)
{
    char *to_ret = NULL;
    int fd = open(filepath, O_RDONLY);
    ssize_t status = 0;

    if (filepath != NULL || fd != -1) {
        to_ret = malloc(sizeof(char) * (BUFF_SIZE + 1));
        status = read(fd, to_ret, BUFF_SIZE);
        if (status <= 0)
            return NULL;
        to_ret[status - 1] = '\0';
    }
    return to_ret;
}

char *load_pipe_entry(void)
{
    char *to_ret = NULL;
    ssize_t status = 0;
    
    to_ret = malloc(sizeof(char) * (BUFF_SIZE + 1));
    status = read(0, to_ret, BUFF_SIZE);
    if (status <= -1){
        free(to_ret);
        return NULL;
    }
    to_ret[status - 1] = '\0';
    return to_ret;
}
