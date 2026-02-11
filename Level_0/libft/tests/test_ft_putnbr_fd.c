#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>
#include <string.h>

// clang-format off

static int	create_pipe(int pipe_fd[2], const int i)
{
  if (pipe(pipe_fd) == -1)
  {
    printf(RED "[FAIL] failed to create a pipe %d \n" RESET, i);
    return (0);
  }
  return (1);
}

int	test_ft_putnbr_fd(void)
{
  int success = 1;
  int pipe_fd[2];
  char buffer[100];
  ssize_t bytes_read;


  //TEST 123456
  if(!create_pipe(pipe_fd, 123456))
  return (0);

  //Call function and write to pipe
  ft_putnbr_fd(123456, pipe_fd[1]);
  close(pipe_fd[1]);

  // Read bytes from the pipe
  bytes_read =  read(pipe_fd[0], buffer, 6);
  close(pipe_fd[0]);

  if (bytes_read != 6 || memcmp(buffer, "123456", bytes_read) != 0)
	{
		printf(RED "[FAIL] ft_putnbr_fd -> basic write mismatch\n" RESET);
		success = 0;
	}

  //TEST "0
  if (!create_pipe(pipe_fd, 0))
  return (0);

  //Call function and write to pipe
  ft_putnbr_fd(0, pipe_fd[1]);
  close(pipe_fd[1]);

  bytes_read = read(pipe_fd[0], buffer, 1);
	close(pipe_fd[0]);

  if (bytes_read != 1)
	{
		printf(RED "[FAIL] ft_putnbr_fd-> 0 should return (0 \n" RESET);
		success = 0;
	}

  // Test 3: Max Int 2147483647
  if (!create_pipe(pipe_fd, 0))
  return (0);

	ft_putnbr_fd(2147483647, pipe_fd[1]);
	close(pipe_fd[1]);
	bytes_read = read(pipe_fd[0], buffer, 10);
	close(pipe_fd[0]);

	if (bytes_read != 10 || memcmp(buffer, "2147483647", 10) != 0)
	{
		printf(RED "[FAIL] ft_putnbr_fd -> max int mismatch\n" RESET);
		success = 0;
	}
  // Test 4: Min Int -2147483648
  if (!create_pipe(pipe_fd, 0))
  return (0);

	ft_putnbr_fd(-2147483648, pipe_fd[1]);
	close(pipe_fd[1]);
	bytes_read = read(pipe_fd[0], buffer, 11);
	close(pipe_fd[0]);

	if (bytes_read != 11 || memcmp(buffer, "-2147483648", 11) != 0)
	{
		printf(RED "[FAIL] ft_putnbr_fd -> min int mismatch\n" RESET);
		success = 0;
	}

  //PRINT Ending
  if (success)
    printf(GREEN "[OK]   ft_putnbr_fd \n" RESET);
  else
    printf(RED "[FAIL] ft_putnbr_fd \n" RESET);
  return (success);
}