#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>

int	test_ft_atoi(void)
{
	int	success;
	int	val;

	success = 1;
	val = ft_atoi("42");
	if (val != 42)
	{
		printf(RED "[FAIL] ft_atoi(\"42\") -> expected 42, got %d\n" RESET, val);
		success = 0;
	}
	val = ft_atoi("   -123abc");
	if (val != -123)
	{
		printf(RED "[FAIL] ft_atoi(\"   -123abc\") -> expected -123, got %d\n"
			RESET, val);
		success = 0;
	}
	val = ft_atoi("+7");
	if (val != 7)
	{
		printf(RED "[FAIL] ft_atoi(\"+7\") -> expected 7, got %d\n" RESET, val);
		success = 0;
	}
	val = ft_atoi("   \t\n 0");
	if (val != 0)
	{
		printf(RED "[FAIL] ft_atoi(\"\\\\t 0\") -> expected 0, got %d\n" RESET,
			val);
		success = 0;
	}
	val = ft_atoi("");
	if (val != 0)
	{
		printf(RED "[FAIL] ft_atoi(\"\") -> expected 0 for empty string\n" RESET);
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_atoi\n" RESET);
	else
		printf(RED "[FAIL] ft_atoi\n" RESET);
	return (success);
}
