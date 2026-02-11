#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>
#include <string.h>

// clang-format off

int	test_ft_putchar_fd(void)
{
	int success = 1;
	int pipe_fd[2];
	char buffer[1];
	char expected = 'A';
	ssize_t bytes_read = 1;

	if (pipe(pipe_fd) == -1)
	{
		printf(RED "[FAIL] failed to create a pipe\n" RESET);
		success = 0;
    return (success);
	}

     // Call your function: write to pipe_fd[1]
    ft_putchar_fd(expected, pipe_fd[1]);

    // Important: close write end before reading
    close(pipe_fd[1]);

    // Read one byte from the pipe
    bytes_read = read(pipe_fd[0], buffer, 1);

    // Close read end
    close(pipe_fd[0]);

    // Now check the results
    // Did we read exactly 1 byte?
    if (bytes_read != 1)
    {
      printf(RED "[FAIL] we didnt read 1 byte\n" RESET);
			success = 0;
    }

    // Does the byte match what we expected?
    if (buffer[0] != expected)
    {
      printf(RED "[FAIL] Bytes did not match\n" RESET);
			success = 0;
    }

  if (success)
		printf(GREEN "[OK]   ft_putchar_fd\n" RESET);
	else
		printf(RED "[FAIL] ft_putchar_fd\n" RESET);
	return (success);
}