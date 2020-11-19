/*
** EPITECH PROJECT, 2019
** read_info
** File description:
** read_info
*/

#include "my.h"

char *clean_date(char *date)
{
    int i = 0;
    int j = 0;
    char *result = malloc(sizeof(char) * my_strlen(date));

    for (i = 0; date[i] && date[i] != ' '; i++);
    for (j = 0; date[i]; j++) {
        result[j] = date[i];
        i++;
    }
    for (j--; result[j] && result[j] != ':'; j--);
    if (result[j])
        result[j] = 0;
    return (result);
}

void calc_last_mod(struct stat info)
{
    char *result = ctime(&info.st_mtime);

    result = clean_date(result);
    my_putstr(result);
    my_putchar(' ');
    free(result);
}

char read_type(struct stat info)
{
    if (info.st_mode & S_IFDIR)
        return ('d');
    if (info.st_mode & S_IFREG)
        return ('-');
    if (info.st_mode & S_IFBLK)
        return ('b');
    if (info.st_mode & S_IFCHR)
        return ('c');
    if (info.st_mode & S_IFIFO)
        return ('p');
    if (info.st_mode & S_IFLNK)
        return ('l');
    if (info.st_mode & S_IFSOCK)
        return ('s');
    return ('-');
}

char read_rights(struct stat info, int pos)
{
    if (pos == 0 && info.st_mode & S_IRUSR)
        return ('r');
    if (pos == 1 && info.st_mode & S_IWUSR)
        return ('w');
    if (pos == 2 && info.st_mode & S_IXUSR)
        return ('x');
    if (pos == 3 && info.st_mode & S_IRGRP)
        return ('r');
    if (pos == 4 && info.st_mode & S_IWGRP)
        return ('w');
    if (pos == 5 && info.st_mode & S_IXGRP)
        return ('x');
    if (pos == 6 && info.st_mode & S_IROTH)
        return ('r');
    if (pos == 7 && info.st_mode & S_IWOTH)
        return ('w');
    if (pos == 8 && info.st_mode & S_IXOTH)
        return ('x');
    return ('-');
}

void read_info(char *file, params *sets)
{
    if (stat(file, &sets->info) < 0)
        return;
    sets->pwd = getpwuid(sets->info.st_uid);
    sets->gr = getgrgid(sets->info.st_gid);
    sets->links = my_intlen(sets->info.st_nlink);
    sets->user = my_strlen(sets->pwd->pw_name);
    sets->group = my_strlen(sets->gr->gr_name);
    sets->weight = my_intlen(sets->info.st_size);
}
