/*
** EPITECH PROJECT, 2019
** parse_errors
** File description:
** parse_errors
*/

#include "my.h"

bool parse_errors(char *folder)
{
    struct stat info;
    int st = stat(folder, &info);

    if (st == -1) {
        my_puterror("ls: cannot access '");
        my_puterror(folder);
        my_puterror("' No such file or directory\n");
        return (false);
    }
    if (!(info.st_mode & S_IFDIR)) {
        my_putstr(folder);
        my_putchar('\n');
        return (false);
    }
    if (!(info.st_mode & S_IROTH)) {
        my_puterror("ls: cannot open directory '");
        my_puterror(folder);
        my_puterror("': Permission denied\n");
        return (false);
    }
    return (true);
}
