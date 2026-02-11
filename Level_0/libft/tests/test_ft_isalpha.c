#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>

int	test_ft_isalpha(void)
{
	int	success;

	success = 1;
	if (ft_isalpha('a') != 1)
	{
		printf(RED "[FAIL] ft_isalpha('a') -> expected 1, got %d\n" RESET,
			ft_isalpha('a'));
		success = 0;
	}
	if (ft_isalpha('1') != 0)
	{
		printf(RED "[FAIL] ft_isalpha('1') -> expected 0, got %d\n" RESET,
			ft_isalpha('1'));
		success = 0;
	}
	if (ft_isalpha('Z') != 1)
	{
		printf(RED "[FAIL] ft_isalpha('Z') -> expected 1, got %d\n" RESET,
			ft_isalpha('Z'));
		success = 0;
	}
	if (ft_isalpha(' ') != 0)
	{
		printf(RED "[FAIL] ft_isalpha(' ') -> expected 0, got %d\n" RESET,
			ft_isalpha(' '));
		success = 0;
	}
	if (ft_isalpha('!') != 0)
	{
		printf(RED "[FAIL] ft_isalpha('!') -> expected 0, got %d\n" RESET,
			ft_isalpha('!'));
		success = 0;
	}
	if (ft_isalpha('\n') != 0)
	{
		printf(RED "[FAIL] ft_isalpha('\\n') -> expected 0, got %d\n" RESET,
			ft_isalpha('\n'));
		success = 0;
	}
	if (ft_isalpha('\t') != 0)
	{
		printf(RED "[FAIL] ft_isalpha('\\t') -> expected 0, got %d\n" RESET,
			ft_isalpha('\t'));
		success = 0;
	}
	if (ft_isalpha('\0') != 0)
	{
		printf(RED "[FAIL] ft_isalpha('\\0') -> expected 0, got %d\n" RESET,
			ft_isalpha('\0'));
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_isalpha\n" RESET);
	else
		printf(RED "[FAIL]   ft_isalpha\n" RESET);
	return (success);
}
