#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>
#include <string.h>

int	test_ft_strnstr(void)
{
	const char	*hay = "find the needle here";
	int			success;
	char		*res;

	success = 1;
	res = ft_strnstr(hay, "needle", strlen(hay));
	if (!res || strcmp(res, "needle here") != 0)
	{
		printf(RED "[FAIL] ft_strnstr -> failed to find substring\n" RESET);
		success = 0;
	}
	res = ft_strnstr(hay, "needle", 5);
	if (res != NULL)
	{
		printf(RED "[FAIL] ft_strnstr -> should respect len and return NULL\n"
			RESET);
		success = 0;
	}
	res = ft_strnstr(hay, "", 3);
	if (res != hay)
	{
		printf(RED "[FAIL] ft_strnstr empty needle -> expected haystack\n"
			RESET);
		success = 0;
	}
	res = ft_strnstr("abcabc", "cab", 4);
	if (res != NULL)
	{
		printf(RED "[FAIL] ft_strnstr -> partial match beyond len should NULL\n"
			RESET);
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_strnstr\n" RESET);
	else
		printf(RED "[FAIL] ft_strnstr\n" RESET);
	return (success);
}
