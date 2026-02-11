#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>

int	test_ft_strlen(void)
{
	int	len;
	int	success;

	success = 1;
	len = ft_strlen("");
	if (len != 0)
	{
		printf(RED "[FAIL] ft_strlen(\"\") -> expected 0, got %d\n" RESET, len);
		success = 0;
	}
	len = ft_strlen("hello");
	if (len != 5)
	{
		printf(RED "[FAIL] ft_strlen(\"hello\") -> expected 5, got %d\n" RESET,
			len);
		success = 0;
	}
	len = ft_strlen("abc\0hidden");
	if (len != 3)
	{
		printf(RED "[FAIL] ft_strlen(\"abc\\\\0hidden\") -> expected 3, got %d\n"
			RESET, len);
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_strlen\n" RESET);
	else
		printf(RED "[FAIL] ft_strlen\n" RESET);
	return (success);
}
