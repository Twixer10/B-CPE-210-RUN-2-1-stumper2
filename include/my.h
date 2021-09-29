/*
** EPITECH PROJECT, 2020
** my
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_
#include "printf.h"

void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_isneg(int n);
void my_put_nbr(int nb);
char **my_str_to_word_array(char const *str);
char **my_str_to_tab(char const *str, char c);
int my_show_word_array(char **tab);
int my_nbr_word(char const *str);
int my_nbr_occ(char const *str, char c);
int my_getnbr(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
char *my_strstr(char *str, char const *to_find);
int my_strncmp(char const *s1, char const *s2, int n);
void my_printf(char const *str, ...);
void my_put_hexa(int nb);
void my_print_number(va_list argv);
void my_print_char(va_list argv);
void my_print_string(va_list argv);
void my_print_hexa(va_list argv);
void check_flags(va_list argv, char flag);
int my_str_isnum_nm(char const *str);
char *load_file_in_mem(char const *filepath);
char *load_pipe_entry(void);
char **str_to_wa(char*str, char sep);
int count_words(char *str, char c);

#endif
