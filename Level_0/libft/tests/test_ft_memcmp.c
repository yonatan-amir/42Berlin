#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>
#include <string.h>

int	test_ft_memcmp(void)
{
	int	success;

	success = 1;
	if (ft_memcmp("abc", "abc", 3) != 0)
	{
		printf(RED "[FAIL] ft_memcmp equal strings should return 0\n" RESET);
		success = 0;
	}
	if (ft_memcmp("abd", "abc", 3) <= 0)
	{
		printf(RED "[FAIL] ft_memcmp -> expected positive when first>second\n"
			RESET);
		success = 0;
	}
	if (ft_memcmp("abc", "abd", 3) >= 0)
	{
		printf(RED "[FAIL] ft_memcmp -> expected negative when first<second\n"
			RESET);
		success = 0;
	}
	if (ft_memcmp("abc", "abd", 0) != 0)
	{
		printf(RED "[FAIL] ft_memcmp n=0 should return 0\n" RESET);
		success = 0;
	}
	if (ft_memcmp("abc", "abz", 2) != 0)
	{
		printf(RED "[FAIL] ft_memcmp should compare only first n bytes\n" RESET);
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_memcmp\n" RESET);
	else
		printf(RED "[FAIL] ft_memcmp\n" RESET);
	return (success);
}
