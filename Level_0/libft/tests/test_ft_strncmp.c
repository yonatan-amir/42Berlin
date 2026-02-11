#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>

int	test_ft_strncmp(void)
{
	int	success;

	success = 1;
	if (ft_strncmp("hello", "hello", 5) != 0)
	{
		printf(RED "[FAIL] ft_strncmp equal strings -> expected 0\n" RESET);
		success = 0;
	}
	if (ft_strncmp("abc", "abd", 3) >= 0)
	{
		printf(RED "[FAIL] ft_strncmp -> expected negative when first<second\n"
			RESET);
		success = 0;
	}
	if (ft_strncmp("abd", "abc", 3) <= 0)
	{
		printf(RED "[FAIL] ft_strncmp -> expected positive when first>second\n"
			RESET);
		success = 0;
	}
	if (ft_strncmp("abcdef", "abcxyz", 3) != 0)
	{
		printf(RED "[FAIL] ft_strncmp should ignore chars beyond n\n" RESET);
		success = 0;
	}
	if (ft_strncmp("abc", "abd", 0) != 0)
	{
		printf(RED "[FAIL] ft_strncmp n=0 should return 0\n" RESET);
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_strncmp\n" RESET);
	else
		printf(RED "[FAIL] ft_strncmp\n" RESET);
	return (success);
}
