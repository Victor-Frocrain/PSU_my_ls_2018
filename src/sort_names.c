/*
** EPITECH PROJECT, 2019
** sort_names
** File description:
** sort_names
*/

#include "my.h"

bool sort_char(char *str1, char *str2)
{
    char c1 = 0;
    char c2 = 0;
    int i = 0;

    for (i = 0; str1[i] && str2[i]; i++) {
        c1 = str1[i];
        c2 = str2[i];
        if (c1 >= 'A' && c1 <= 'Z')
            c1 += 32;
        if (c2 >= 'A' && c2 <= 'Z')
            c2 += 32;
        if (c1 > c2)
            return (false);
        else if (c2 > c1)
            return (true);
    }
    if (str1[i] && !str2[i])
        return (false);
    return (true);
}

char **sort_names(char **contents)
{
    char *buff = NULL;

    for (int i = 0; contents[i] && contents[i + 1];) {
        if (sort_char(contents[i], contents[i + 1]) == false) {
            buff = malloc(sizeof(char) * my_strlen(contents[i]));
            buff = my_strcpy(buff, contents[i]);
            contents[i] = malloc(sizeof(char) * my_strlen(contents[i + 1]));
            contents[i] = my_strcpy(contents[i], contents[i + 1]);
            contents[i + 1] = malloc(sizeof(char) * my_strlen(buff));
            contents[i + 1] = my_strcpy(contents[i + 1], buff);
            free(buff);
            i = 0;
        }
        else
            i++;
    }
    return (contents);
}
