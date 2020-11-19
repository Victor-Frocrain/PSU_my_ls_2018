/*
** EPITECH PROJECT, 2019
** print_special
** File description:
** print_special
*/

#include "my.h"

char **copy_elem(char **copy, char **contents, count *nb, char *folder)
{
    int i = 0;
    struct stat info;
    int st = 0;

    copy = malloc(sizeof(char *) * (nb->nb + 1));
    for (int j = 0; contents[j]; j++) {
        st = stat(my_strcat(folder, contents[j]), &info);
        if (st == 0) {
            copy[i] = contents[j];
            i++;
        }
    }
    copy[i] = NULL;
    return (copy);
}

char **print_special(int size, flags *f, char **contents)
{
    if (f->reverse)
        contents = reverse_order(contents);
    if (f->list) {
        my_putstr("total ");
        my_put_nbr(size / 2);
        my_putchar('\n');
    }
    return (contents);
}

void print_all(count *nb, char **contents, flags *f, char *folder)
{
    params **files = malloc(sizeof(params *) * nb->nb);
    char **copy = copy_elem(copy, contents, nb, folder);
    int j = 0;
    lengths *sizes = malloc(sizeof(lengths));

    copy = sort_names(copy);
    copy = print_special(nb->total, f, copy);
    for (j = 0; copy[j] && j < nb->nb; j++) {
        files[j] = malloc(sizeof(params));
        read_info(my_strcat(folder, copy[j]), files[j]);
    }
    files[j] = NULL;
    if (f->time)
        copy = sort_time2(files, copy);
    calc_max_sizes(sizes, files);
    for (int i = 0; copy[i]; i++) {
        if (f->list)
            print_info(files[i], sizes);
        my_putstr(copy[i]);
        my_putchar('\n');
    }
}
