/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

flags *init_flags(flags *f)
{
    f = malloc(sizeof(flags));
    f->list = false;
    f->recurse = false;
    f->reverse = false;
    return (f);
}

char **detect_folder(char **av, int ac)
{
    char **folder = malloc(sizeof(char *) * ac);
    int j = 0;

    for (int i = 1; av[i]; i++) {
        if (av[i][0] && av[i][0] != '-') {
            folder[j] = malloc(sizeof(char) * my_strlen(av[i]));
            folder[j] = my_strcpy(folder[j], av[i]);
            j++;
        }
    }
    folder[j] = NULL;
    return (folder);
}

char *detect_flags(char *str, flags *f)
{
    if (str[0] && str[0] != '-')
        return (str);
    for (int i = 1; str[i]; i++) {
        if (str[i] == 'l')
            f->list = true;
        if (str[i] == 'R')
            f->recurse = true;
        if (str[i] == 'r')
            f->reverse = true;
        if (str[i] == 'd')
            f->direct = true;
        if (str[i] == 't')
            f->time = true;
    }
}

int main(int ac, char **av)
{
    char **folder = NULL;
    flags *f = init_flags(f);
    bool multi = false;

    folder = detect_folder(av, ac);
    if (folder && folder[0] == NULL)
        folder[0] = "./";
    for (int i = 0; av[i]; i++)
        detect_flags(av[i], f);
    folder = sort_names(folder);
    if (f->time)
        folder = sort_time(folder);
    if (folder[1])
        multi = true;
    for (int i = 0; folder[i]; i++) {
        open_folder(folder[i], multi, f);
        if (folder[i + 1])
            my_putchar('\n');
    }
    return (MY_EXIT_SUCCESS);
}
