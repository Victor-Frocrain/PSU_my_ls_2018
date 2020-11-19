/*
** EPITECH PROJECT, 2019
** calc_max_sizes
** File description:
** calc_max_sizes
*/

#include "my.h"

void calc_max_sizes(lengths *sizes, params **sets)
{
    sizes->links_max = 0;
    sizes->user_max = 0;
    sizes->group_max = 0;
    sizes->weight_max = 0;
    for (int i = 0; sets[i]; i++) {
        if (sizes->links_max < sets[i]->links)
            sizes->links_max = sets[i]->links;
        if (sizes->user_max < sets[i]->user)
            sizes->user_max = sets[i]->user;
        if (sizes->group_max < sets[i]->group)
            sizes->group_max = sets[i]->group;
        if (sizes->weight_max < sets[i]->weight)
            sizes->weight_max = sets[i]->weight;
    }
}
