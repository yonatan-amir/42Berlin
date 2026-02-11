#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	test_ft_strtrim(void)
{
	int		success;
	char	*res;

	success = 1;
	res = ft_strtrim("--hello", "-");
	if (!res || strcmp(res, "hello") != 0)
	{
		printf(RED "[FAIL] ft_strtrim -> expected hello got %s\n" RESET,
			res ? res : "(null)");
		success = 0;
	}
	free(res);
	if (success)
		printf(GREEN "[OK]   ft_strtrim\n" RESET);
	else
		printf(RED "[FAIL] ft_strtrim\n" RESET);
	return (success);
}
