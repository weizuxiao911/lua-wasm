#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include "ls.h"

void ls(const char *path)
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);
    if (!dir)
    {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}
