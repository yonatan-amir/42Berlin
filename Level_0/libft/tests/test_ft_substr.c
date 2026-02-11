#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	test_ft_substr(void)
{
	int		success;
	char	*res;

	success = 1;
	res = ft_substr("hello world", 6, 5);
	if (!res || strcmp(res, "world") != 0)
	{
		printf(RED "[FAIL] ft_substr basic -> expected \"world\"\n" RESET);
		success = 0;
	}
	free(res);
	res = ft_substr("short", 10, 3);
	if (!res || res[0] != '\0')
	{
		printf(RED "[FAIL] ft_substr start beyond length -> should be \"\"\n"
			RESET);
		success = 0;
	}
	free(res);
	res = ft_substr("truncate", 2, 50);
	if (!res || strcmp(res, "uncate") != 0)
	{
		printf(RED "[FAIL] ft_substr len beyond end -> expected \"uncate\"\n"
			RESET);
		success = 0;
	}
	free(res);
	if (success)
		printf(GREEN "[OK]   ft_substr\n" RESET);
	else
		printf(RED "[FAIL] ft_substr\n" RESET);
	return (success);
}
