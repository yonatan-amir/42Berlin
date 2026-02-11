#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>
#include <string.h>

// clang-format off

static int	create_pipe(int pipe_fd[2], const char *s)
{
  if (pipe(pipe_fd) == -1)
  {
    printf(RED "[FAIL] failed to create a pipe %s \n" RESET, s);
    return (0);
  }
  return (1);
}

int	test_ft_putendl_fd(void)
{
  int success = 1;
  int pipe_fd[2];
  char buffer[100];
  ssize_t bytes_read;


  //TEST Hello
  if(!create_pipe(pipe_fd, "Hello"))
    return (0);

  //Call function and write to pipe
  ft_putendl_fd("Hello", pipe_fd[1]);
  close(pipe_fd[1]);

  // Read bytes from the pipe
  bytes_read =  read(pipe_fd[0], buffer, 6);
  close(pipe_fd[0]);

  if (bytes_read != 6 || memcmp(buffer, "Hello\n", bytes_read) != 0)
	{
		printf(RED "[FAIL] ft_putendl_fd -> basic write mismatch\n" RESET);
		success = 0;
	}

  //TEST ""
  if (!create_pipe(pipe_fd, ""))
  return (0);

  //Call function and write to pipe
  ft_putendl_fd("", pipe_fd[1]);
  close(pipe_fd[1]);

  bytes_read = read(pipe_fd[0], buffer, 1);
	close(pipe_fd[0]);

  if (bytes_read != 1)
	{
		printf(RED "[FAIL] ft_putendl_fd-> empty string should write 1 bytes\n" RESET);
		success = 0;
	}

  // Test 3: Longer string
  if (!create_pipe(pipe_fd, "Long"))
    return (0);

	char *long_str = "This is a longer test string";
	size_t len = strlen(long_str);

	ft_putendl_fd(long_str, pipe_fd[1]);
	close(pipe_fd[1]);
	bytes_read = read(pipe_fd[0], buffer, len + 1);
	close(pipe_fd[0]);

	if (bytes_read != (ssize_t)len + 1 || memcmp(buffer,
			"This is a longer test string\n" , len
			+ 1) != 0)
	{
		printf(RED "[FAIL] ft_putendl_fd -> long string mismatch\n" RESET);
		success = 0;
	}

    // Test 4: String is NULL
  if (!create_pipe(pipe_fd, "NULL"))
    return (0);

	ft_putendl_fd(NULL, pipe_fd[1]);
	close(pipe_fd[1]);
	bytes_read = read(pipe_fd[0], buffer, 1);
	close(pipe_fd[0]);

	if (bytes_read != 0)
	{
		printf(RED "[FAIL] ft_putendl_fd -> expected 0 bytes returned\n" RESET);
		success = 0;
	}

  //PRINT Ending
  if (success)
    printf(GREEN "[OK]   ft_putendl_fd \n" RESET);
  else
    printf(RED "[FAIL] ft_putendl_fd \n" RESET);
  return (success);
}