/*
** EPITECH PROJECT, 2019
** print_info
** File description:
** print_info
*/

#include "my.h"

void print_spaces(int nb, int max)
{
    for (int i = 0; i <= max - nb; i++)
        my_putchar(' ');
}

void print_info(params *sets, lengths *sizes)
{
    my_putchar(read_type(sets->info));
    for (int i = 0; i < 9; i++)
        my_putchar(read_rights(sets->info, i));
    my_putstr(".");
    print_spaces(sets->links, sizes->links_max);
    my_put_nbr(sets->info.st_nlink);
    print_spaces(sets->user, sizes->user_max);
    my_putstr(sets->pwd->pw_name);
    print_spaces(sets->group, sizes->group_max);
    my_putstr(sets->gr->gr_name);
    print_spaces(sets->weight, sizes->weight_max);
    my_put_nbr(sets->info.st_size);
    calc_last_mod(sets->info);
}
