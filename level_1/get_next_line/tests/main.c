#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../get_next_line/get_next_line.h"

static void read_all(int fd)
{
    char *line;
    int count = 0;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%03d: %s", count, line);
        free(line);
        count++;
    }
}

int main(int argc, char **argv)
{
    int fd;

    if (argc == 1)
    {
        read_all(STDIN_FILENO);
        return 0;
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    read_all(fd);
    close(fd);
    return 0;
}
