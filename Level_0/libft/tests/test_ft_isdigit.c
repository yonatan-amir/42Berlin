#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>

int	test_ft_isdigit(void)
{
	int	success;

	success = 1;
	// Digits that should return 1
	if (ft_isdigit('0') != 1)
	{
		printf(RED "[FAIL] ft_isdigit('0') -> expected 1, got %d\n" RESET,
			ft_isdigit('0'));
		success = 0;
	}
	if (ft_isdigit('5') != 1)
	{
		printf(RED "[FAIL] ft_isdigit('5') -> expected 1, got %d\n" RESET,
			ft_isdigit('5'));
		success = 0;
	}
	if (ft_isdigit('9') != 1)
	{
		printf(RED "[FAIL] ft_isdigit('9') -> expected 1, got %d\n" RESET,
			ft_isdigit('9'));
		success = 0;
	}
	// Non-digits that should return 0
	if (ft_isdigit('a') != 0)
	{
		printf(RED "[FAIL] ft_isdigit('a') -> expected 0, got %d\n" RESET,
			ft_isdigit('a'));
		success = 0;
	}
	if (ft_isdigit(' ') != 0)
	{
		printf(RED "[FAIL] ft_isdigit(' ') -> expected 0, got %d\n" RESET,
			ft_isdigit(' '));
		success = 0;
	}
	if (ft_isdigit('!') != 0)
	{
		printf(RED "[FAIL] ft_isdigit('!') -> expected 0, got %d\n" RESET,
			ft_isdigit('!'));
		success = 0;
	}
	if (ft_isdigit('\n') != 0)
	{
		printf(RED "[FAIL] ft_isdigit('\\n') -> expected 0, got %d\n" RESET,
			ft_isdigit('\n'));
		success = 0;
	}
	if (ft_isdigit('\t') != 0)
	{
		printf(RED "[FAIL] ft_isdigit('\\t') -> expected 0, got %d\n" RESET,
			ft_isdigit('\t'));
		success = 0;
	}
	if (ft_isdigit('\0') != 0)
	{
		printf(RED "[FAIL] ft_isdigit('\\0') -> expected 0, got %d\n" RESET,
			ft_isdigit('\0'));
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_isdigit\n" RESET);
	else
		printf(RED "[FAIL] ft_isdigit\n" RESET);
	return (success);
}
