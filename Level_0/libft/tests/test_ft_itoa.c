#include "../libft/libft.h"
#include "tests.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	test_ft_itoa(void)
{
	int		success;
	char	*res;

	success = 1;
	// ------------------------------
	// Basic positive number
	// ------------------------------
	res = ft_itoa(12345);
	if (!res || strcmp(res, "12345") != 0)
	{
		printf(RED "[FAIL] ft_itoa -> basic positive integer\n" RESET);
		success = 0;
	}
	free(res);
	// ------------------------------
	// Zero
	// ------------------------------
	res = ft_itoa(0);
	if (!res || strcmp(res, "0") != 0)
	{
		printf(RED "[FAIL] ft_itoa -> zero case\n" RESET);
		success = 0;
	}
	free(res);
	// ------------------------------
	// Negative number
	// ------------------------------
	res = ft_itoa(-42);
	if (!res || strcmp(res, "-42") != 0)
	{
		printf(RED "[FAIL] ft_itoa -> negative integer\n" RESET);
		success = 0;
	}
	free(res);
	// ------------------------------
	// INT_MAX
	// ------------------------------
	res = ft_itoa(INT_MAX);
	if (!res || strcmp(res, "2147483647") != 0)
	{
		printf(RED "[FAIL] ft_itoa -> INT_MAX\n" RESET);
		success = 0;
	}
	free(res);
	// ------------------------------
	// INT_MIN
	// ------------------------------
	res = ft_itoa(INT_MIN);
	if (!res || strcmp(res, "-2147483648") != 0)
	{
		printf(RED "[FAIL] ft_itoa -> INT_MIN\n" RESET);
		success = 0;
	}
	free(res);
	// ------------------------------
	// Random negative
	// ------------------------------
	res = ft_itoa(-987654);
	if (!res || strcmp(res, "-987654") != 0)
	{
		printf(RED "[FAIL] ft_itoa -> random negative\n" RESET);
		success = 0;
	}
	free(res);
	// ------------------------------
	// Random positive
	// ------------------------------
	res = ft_itoa(999999);
	if (!res || strcmp(res, "999999") != 0)
	{
		printf(RED "[FAIL] ft_itoa -> random positive\n" RESET);
		success = 0;
	}
	free(res);
	// ==============================
	// FINAL RESULT
	// ==============================
	if (success)
		printf(GREEN "[OK]   ft_itoa\n" RESET);
	else
		printf(RED "[FAIL] ft_itoa\n" RESET);
	return (success);
}
