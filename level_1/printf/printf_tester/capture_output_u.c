#include "capture_output.h"
#include "limits.h"

int	capture_output_u(int (*fn)(const char *, ...), const char *fmt,
		char *buffer, size_t buffer_size, unsigned int arg)
{
	int		pipe_fd[2];
	int		saved_stdout;
	ssize_t	bytes_read;
	int		ret;
	int		saved_dup;

	if (pipe(pipe_fd) == -1)
		return (-1);
	saved_stdout = dup(1);
	if (saved_stdout == -1)
		return (-1);
	fflush(stdout);
	saved_dup = dup2(pipe_fd[1], 1);
	if (saved_dup == -1)
		return (-1);
	close(pipe_fd[1]);
	ret = fn(fmt, arg);
	fflush(stdout);
	if (dup2(saved_stdout, 1) == -1)
		return (-1);
	close(saved_stdout);
	bytes_read = read(pipe_fd[0], buffer, buffer_size - 1);
	close(pipe_fd[0]);
	if (bytes_read < 0)
		return (-1);
	buffer[bytes_read] = '\0';
	return (ret);
}
