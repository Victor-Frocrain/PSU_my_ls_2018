/*
** EPITECH PROJECT, 2019
** open_folder
** File description:
** open_folder
*/

#include "my.h"

int read_size(struct dirent *dir, char *folder)
{
    struct stat info;

    stat(my_strcat(folder, dir->d_name), &info);
    if (dir && dir->d_name && dir->d_name[0] == '.')
        return (0);
    return (info.st_blocks);
}

char **my_realloc(char **contents, count *nb)
{
    char **new = NULL;
    int i = 0;

    for (i = 0; contents[i]; i++);
    new = malloc(sizeof(char *) * (i + 2));
    if (new == NULL)
        return (NULL);
    for (i = 0; contents[i] && i <= nb->use; i++) {
        new[i] = malloc(sizeof(char) * my_strlen(contents[i]));
        if (new[i] == NULL)
            return (NULL);
        new[i] = my_memset(new[i], 0, my_strlen(contents[i]));
        new[i] = my_strcpy(new[i], contents[i]);
    }
    new[i] = NULL;
    free(contents);
    return (new);
}

char **fill_names(struct dirent *dir, char **contents, count *nb)
{
    int i = 0;

    for (i = 0; contents[i] && contents[i][0]; i++);
    if (dir->d_name && dir->d_name[0] != '.') {
        if (contents == NULL)
            return (NULL);
        contents[i] = malloc(sizeof(char) * my_strlen(dir->d_name));
        if (contents[i] == NULL)
            return (NULL);
        contents[i] = my_memset(contents[i], 0, my_strlen(dir->d_name));
        contents[i] = my_strcpy(contents[i], dir->d_name);
        contents = my_realloc(contents, nb);
        nb->use++;
    }
    return (contents);
}

bool read_folder(DIR *rd, flags *f, char *folder)
{
    struct dirent *dir = readdir(rd);
    char **contents = malloc(sizeof(char *));
    count *nb = malloc(sizeof(count));

    nb->total = 0;
    nb->use = 0;
    for (nb->nb = 0; dir; nb->nb++) {
        contents = fill_names(dir, contents, nb);
        if (contents == NULL)
            return (false);
        nb->total += read_size(dir, folder);
        dir = readdir(rd);
    }
    print_all(nb, contents, f, folder);
    for (int i = 0; contents[i]; i++)
        free(contents[i]);
    free(contents);
    return (true);
}

void open_folder(char *folder, bool multi, flags *f)
{
    DIR *rd;
    char *origin_name = malloc(sizeof(char) * my_strlen(folder));

    origin_name = my_strcpy(origin_name, folder);
    if (parse_errors(folder) == false)
        return;
    folder = my_strcat(folder, "/");
    rd = opendir(folder);
    if (rd == NULL) {
        return;
    }
    if (multi) {
        my_putstr(origin_name);
        my_putstr(":\n");
    }
    if (read_folder(rd, f, folder) == false)
        return;
}
