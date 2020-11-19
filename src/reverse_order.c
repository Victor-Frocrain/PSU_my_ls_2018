/*
** EPITECH PROJECT, 2019
** reverse_order
** File description:
** reverse_order
*/

#include "my.h"

char **reverse_order(char **contents)
{
    char **result = NULL;
    int i = 0;
    int j = 0;

    for (i = 0; contents[i]; i++);
    result = malloc(sizeof(char *) * i);
    for (i--; i >= 0 && contents[i]; i--) {
        result[j] = malloc(sizeof(char) * my_strlen(contents[i]));
        result[j] = my_strcpy(result[j], contents[i]);
        j++;
    }
    result[j] = NULL;
    return (result);
}
