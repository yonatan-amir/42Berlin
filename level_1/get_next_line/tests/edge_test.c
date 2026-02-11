#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../get_next_line/get_next_line.h"

static void	write_line(int fd, int len, int add_nl, char ch)
{
	char	*buf;

	if (len <= 0)
		return ;
	buf = malloc((size_t)len);
	if (!buf)
		return ;
	memset(buf, ch, (size_t)len);
	write(fd, buf, (size_t)len);
	if (add_nl)
		write(fd, "\n", 1);
	free(buf);
}

static int	build_file(char *path, size_t path_size)
{
	char	tmpl[] = "/tmp/gnl_edge_XXXXXX";
	int		fd;

	fd = mkstemp(tmpl);
	if (fd < 0)
		return (-1);
	strncpy(path, tmpl, path_size - 1);
	path[path_size - 1] = '\0';
	write_line(fd, BUFFER_SIZE - 1, 1, 'A');
	write_line(fd, BUFFER_SIZE, 1, 'B');
	write_line(fd, BUFFER_SIZE + 1, 1, 'C');
	write_line(fd, BUFFER_SIZE, 0, 'D');
	close(fd);
	return (0);
}

static void	print_line_info(int i, char *line)
{
	size_t	len;
	size_t	j;
	unsigned char	c;

	len = strlen(line);
	printf("%03d: len=%zu line=\"", i, len);
	j = 0;
	while (j < len)
	{
		c = (unsigned char)line[j];
		if (c == '\n')
			printf("\\n");
		else if (c == '\t')
			printf("\\t");
		else if (c == '\r')
			printf("\\r");
		else if (c == '\\')
			printf("\\\\");
		else if (c < 32 || c == 127)
			printf("\\x%02x", c);
		else
			printf("%c", c);
		j++;
	}
	printf("\"\n");
}

int	main(void)
{
	char	path[256];
	int		fd;
	char	*line;
	int		i;

	if (build_file(path, sizeof(path)) != 0)
		return (1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		print_line_info(i, line);
		free(line);
		i++;
	}
	close(fd);
	unlink(path);
	return (0);
}
