#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	test_ft_strjoin(void)
{
	int		success;
	char	*res;

	success = 1;
	res = ft_strjoin("hello", "world");
	if (!res || strcmp(res, "helloworld") != 0)
	{
		printf(RED "[FAIL] ft_strjoin -> concatenation incorrect\n" RESET);
		success = 0;
	}
	free(res);
	res = ft_strjoin("", "suffix");
	if (!res || strcmp(res, "suffix") != 0)
	{
		printf(RED "[FAIL] ft_strjoin with empty prefix failed\n" RESET);
		success = 0;
	}
	free(res);
	res = ft_strjoin(NULL, "test");
	if (res != NULL)
	{
		printf(RED "[FAIL] ft_strjoin NULL input -> expected NULL\n" RESET);
		free(res);
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_strjoin\n" RESET);
	else
		printf(RED "[FAIL] ft_strjoin\n" RESET);
	return (success);
}
