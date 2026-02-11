#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>

int	test_ft_strchr(void)
{
	const char	*s = "hello";
	int			success;
	char		*res;

	success = 1;
	res = ft_strchr(s, 'l');
	if (!res || res != s + 2)
	{
		printf(RED "[FAIL] ft_strchr -> expected pointer to first 'l'\n" RESET);
		success = 0;
	}
	res = ft_strchr(s, 'z');
	if (res != NULL)
	{
		printf(RED "[FAIL] ft_strchr -> expected NULL when char missing\n" RESET);
		success = 0;
	}
	res = ft_strchr(s, '\0');
	if (res != s + 5)
	{
		printf(RED "[FAIL] ft_strchr -> should return pointer to terminator\n"
			RESET);
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_strchr\n" RESET);
	else
		printf(RED "[FAIL] ft_strchr\n" RESET);
	return (success);
}
