/*
** EPITECH PROJECT, 2019
** my_intlen
** File description:
** my_intlen
*/

#include "my.h"

int my_intlen(int nb)
{
    int i = 0;

    for (i = 0; nb > 0; i++)
        nb /= 10;
    return (i);
}
