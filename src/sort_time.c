/*
** EPITECH PROJECT, 2019
** sort_time
** File description:
** sort_time
*/

#include "my.h"

char **loop_sort_time(char **contents, time_t *t)
{
    time_t temp1 = 0;
    char *temp2 = NULL;
    int i = 0;

    for (i = 0; t[i] && contents[i];) {
        if (t[i + 1] && contents[i + 1] && t[i] < t[i + 1]) {
            temp1 = t[i];
            t[i] = t[i + 1];
            t[i + 1] = temp1;
            temp2 = contents[i];
            contents[i] = contents[i + 1];
            contents[i + 1] = temp2;
            i = 0;
        }
        else
            i++;
    }
    contents[i] = NULL;
    return (contents);
}

char **sort_time(char **contents)
{
    struct stat info;
    time_t *t = NULL;
    int nb = 0;

    for (nb = 0; contents[nb]; nb++);
    t = malloc(sizeof(time_t) * nb);
    if (t == NULL)
        exit(MY_EXIT_ERROR);
    for (int i = 0; contents[i]; i++) {
        stat(contents[i], &info);
        t[i] = info.st_mtime;
    }
    return (loop_sort_time(contents, t));
    return (contents);
}

char **sort_time2(params **sets, char **contents)
{
    params *temp1;
    char *temp2;

    for (int i = 0; sets[i] && contents[i];) {
        if ((sets[i + 1] && contents[i + 1] &&
        sets[i]->info.st_mtime < sets[i + 1]->info.st_mtime)) {
            temp2 = contents[i];
            contents[i] = contents[i + 1];
            contents[i + 1] = temp2;
            temp1 = sets[i];
            sets[i] = sets[i + 1];
            sets[i + 1] = temp1;
            i = 0;
        }
        else
            i++;
    }
    return (contents);
}
