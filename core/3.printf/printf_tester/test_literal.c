#include "../libftprintf/ft_printf.h"
#include "test_runner.h"

int	capture_output(int (*fn)(const char *, ...), const char *fmt, char *buffer,
		size_t buffer_size)
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
	saved_dup = dup2(pipe_fd[1], 1);
	if (saved_dup == -1)
		return (-1);
	close(pipe_fd[1]);
	ret = fn(fmt);
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

int	test_literal(void)
{
	int success = 1;
	const char *str = "string_compare";
	char buffer_printf[128];
	char buffer_ft[128];
	int r_printf;
	int r_ft;

	r_printf = capture_output(printf, str, buffer_printf,
			sizeof(buffer_printf));
	r_ft = capture_output(ft_printf, str, buffer_ft, sizeof(buffer_ft));
	if (r_ft == -1 || r_printf == -1)
	{
		success = 0;
		printf(RED "capture output failed\n" RESET);
	}
	if (r_printf != r_ft | strcmp(buffer_printf, buffer_ft) != 0)
		success = 0;

	if (!success)
	{
		printf("EXPECTED string to be equal to %s but output was %s \n\n", str,
			buffer_ft);
		if (r_printf != r_ft)
			printf("EXPECTED %d to be equal to %d\n\n", r_printf, r_ft);
	}

	if (success)
		printf(GREEN "TEST_LITERAL [OK]\n" RESET);
	else
		printf(RED "TEST_LITERAL [FAIL]\n" RESET);
	return (success);
}