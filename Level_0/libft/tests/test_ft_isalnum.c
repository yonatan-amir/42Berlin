#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>

int	test_ft_isalnum(void)
{
	int	success;

	success = 1;
	// Alphanumeric: should return 1
	if (ft_isalnum('a') != 1)
	{
		printf(RED "[FAIL] ft_isalnum('a') -> expected 1, got %d\n" RESET,
			ft_isalnum('a'));
		success = 0;
	}
	if (ft_isalnum('Z') != 1)
	{
		printf(RED "[FAIL] ft_isalnum('Z') -> expected 1, got %d\n" RESET,
			ft_isalnum('Z'));
		success = 0;
	}
	if (ft_isalnum('0') != 1)
	{
		printf(RED "[FAIL] ft_isalnum('0') -> expected 1, got %d\n" RESET,
			ft_isalnum('0'));
		success = 0;
	}
	if (ft_isalnum('9') != 1)
	{
		printf(RED "[FAIL] ft_isalnum('9') -> expected 1, got %d\n" RESET,
			ft_isalnum('9'));
		success = 0;
	}
	// Non-alphanumeric: should return 0
	if (ft_isalnum(' ') != 0)
	{
		printf(RED "[FAIL] ft_isalnum(' ') -> expected 0, got %d\n" RESET,
			ft_isalnum(' '));
		success = 0;
	}
	if (ft_isalnum('!') != 0)
	{
		printf(RED "[FAIL] ft_isalnum('!') -> expected 0, got %d\n" RESET,
			ft_isalnum('!'));
		success = 0;
	}
	if (ft_isalnum('\n') != 0)
	{
		printf(RED "[FAIL] ft_isalnum('\\n') -> expected 0, got %d\n" RESET,
			ft_isalnum('\n'));
		success = 0;
	}
	if (ft_isalnum('\t') != 0)
	{
		printf(RED "[FAIL] ft_isalnum('\\t') -> expected 0, got %d\n" RESET,
			ft_isalnum('\t'));
		success = 0;
	}
	if (ft_isalnum('\0') != 0)
	{
		printf(RED "[FAIL] ft_isalnum('\\0') -> expected 0, got %d\n" RESET,
			ft_isalnum('\0'));
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_isalnum\n" RESET);
	else
		printf(RED "[FAIL] ft_isalnum\n" RESET);
	return (success);
}
