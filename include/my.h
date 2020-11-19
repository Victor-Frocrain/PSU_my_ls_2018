/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <errno.h>

#define MY_EXIT_ERROR 84
#define MY_EXIT_SUCCESS 0
#ifndef MY_H_
#define MY_H_

typedef struct flags_t {
    bool list;
    bool recurse;
    bool reverse;
    bool direct;
    bool time;
} flags;

typedef struct params_t {
    struct stat info;
    struct passwd *pwd;
    struct group *gr;
    int links;
    int user;
    int group;
    int weight;
} params;

typedef struct lengths_t {
    int links_max;
    int user_max;
    int group_max;
    int weight_max;
} lengths;

typedef struct count_t {
    int nb;
    int total;
    int use;
} count;

int my_strcmp(char const *s1, char const *s2);
char *convert_int_str(int nb);
char *my_revstr(char *str);
int my_strlen(char *str);
int my_getnbr(char const *str);
void my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_memset(char *str, char c, int size);
char *my_strcpy(char *dest, char const *src);
void open_folder(char *folder, bool multi, flags *f);
char **sort_names(char **contents);
void read_info(char *file, params *sets);
char *my_strcat(char *str1, char *str2);
char **reverse_order(char **contents);
char **print_special(int size, flags *f, char **contents);
void print_all(count *nb, char **contents, flags *f, char *folder);
void my_puterror(char *str);
bool parse_errors(char *folder);
void print_info(params *sets, lengths *sizes);
char read_rights(struct stat info, int pos);
char read_type(struct stat info);
void calc_last_mod(struct stat info);
int my_intlen(int nb);
void calc_max_sizes(lengths *sizes, params **sets);
char **sort_time(char **contents);
char **sort_time2(params **sets, char **contents);
params **sort_info_time(params **sets, char **contents);
bool sort_char(char *str1, char *str2);

#endif /* MY_H_ */
