#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../_source/get_next_line_bonus.h"

static void print_line(const char *tag, char *line, int index)
{
    if (line)
        printf("%s %03d: %s", tag, index, line);
}

int main(int argc, char **argv)
{
    int fd_a;
    int fd_b;
    char *line_a;
    char *line_b;
    int i;

    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }
    fd_a = open(argv[1], O_RDONLY);
    fd_b = open(argv[2], O_RDONLY);
    if (fd_a < 0 || fd_b < 0)
    {
        perror("open");
        if (fd_a >= 0)
            close(fd_a);
        if (fd_b >= 0)
            close(fd_b);
        return 1;
    }
    i = 0;
    while (1)
    {
        line_a = get_next_line(fd_a);
        line_b = get_next_line(fd_b);
        if (!line_a && !line_b)
            break;
        print_line("A", line_a, i);
        print_line("B", line_b, i);
        free(line_a);
        free(line_b);
        i++;
    }
    close(fd_a);
    close(fd_b);
    return 0;
}
