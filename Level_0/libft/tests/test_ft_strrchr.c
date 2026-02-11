#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>

int	test_ft_strrchr(void)
{
	const char	*s = "banana";
	int			success;
	char		*res;

	success = 1;
	res = ft_strrchr(s, 'a');
	if (!res || res != s + 5)
	{
		printf(RED "[FAIL] ft_strrchr -> expected pointer to last 'a'\n" RESET);
		success = 0;
	}
	res = ft_strrchr(s, 'z');
	if (res != NULL)
	{
		printf(RED "[FAIL] ft_strrchr -> expected NULL when char missing\n"
			RESET);
		success = 0;
	}
	res = ft_strrchr(s, '\0');
	if (res != s + 6)
	{
		printf(RED "[FAIL] ft_strrchr -> should point to string terminator\n"
			RESET);
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_strrchr\n" RESET);
	else
		printf(RED "[FAIL] ft_strrchr\n" RESET);
	return (success);
}
