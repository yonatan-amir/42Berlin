#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>

int	test_ft_tolower(void)
{
	int	success;

	success = 1;
	// Uppercase letters -> lowercase
	if (ft_tolower('A') != 'a')
	{
		printf(RED "[FAIL] ft_tolower('A') -> expected 'a', got '%c'\n" RESET,
			ft_tolower('A'));
		success = 0;
	}
	if (ft_tolower('Z') != 'z')
	{
		printf(RED "[FAIL] ft_tolower('Z') -> expected 'z', got '%c'\n" RESET,
			ft_tolower('Z'));
		success = 0;
	}
	if (ft_tolower('M') != 'm')
	{
		printf(RED "[FAIL] ft_tolower('M') -> expected 'm', got '%c'\n" RESET,
			ft_tolower('M'));
		success = 0;
	}
	// Lowercase letters -> unchanged
	if (ft_tolower('a') != 'a')
	{
		printf(RED "[FAIL] ft_tolower('a') -> expected 'a', got '%c'\n" RESET,
			ft_tolower('a'));
		success = 0;
	}
	if (ft_tolower('z') != 'z')
	{
		printf(RED "[FAIL] ft_tolower('z') -> expected 'z', got '%c'\n" RESET,
			ft_tolower('z'));
		success = 0;
	}
	// Non-letters -> unchanged
	if (ft_tolower('0') != '0')
	{
		printf(RED "[FAIL] ft_tolower('0') -> expected '0', got '%c'\n" RESET,
			ft_tolower('0'));
		success = 0;
	}
	if (ft_tolower('!') != '!')
	{
		printf(RED "[FAIL] ft_tolower('!') -> expected '!', got '%c'\n" RESET,
			ft_tolower('!'));
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_tolower\n" RESET);
	else
		printf(RED "[FAIL] ft_tolower\n" RESET);
	return (success);
}
