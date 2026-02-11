#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>
#include <string.h>

int	test_ft_strlcpy(void)
{
	char	dst[6];
	int		success;
	size_t	ret;

	success = 1;
	ret = ft_strlcpy(dst, "hello", sizeof(dst));
	if (ret != 5 || strcmp(dst, "hello") != 0)
	{
		printf(RED "[FAIL] ft_strlcpy -> basic copy or return length wrong\n"
			RESET);
		success = 0;
	}
	memset(dst, 'x', sizeof(dst));
	ret = ft_strlcpy(dst, "world", 1);
	if (ret != 5 || dst[0] != '\0' || dst[1] != 'x')
	{
		printf(RED "[FAIL] ft_strlcpy size 1 -> incorrect behavior\n" RESET);
		success = 0;
	}
	memset(dst, 'y', sizeof(dst));
	ret = ft_strlcpy(dst, "abc", 0);
	if (ret != 3 || dst[0] != 'y')
	{
		printf(RED "[FAIL] ft_strlcpy size 0 -> should return src len\n" RESET);
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_strlcpy\n" RESET);
	else
		printf(RED "[FAIL] ft_strlcpy\n" RESET);
	return (success);
}
