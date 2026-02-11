#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>
#include <string.h>

int	test_ft_strlcat(void)
{
	char	dst[12] = "hello";
	char	small[7] = "abc";
	size_t	ret;
	int		success;

	success = 1;
	ret = ft_strlcat(dst, " world", sizeof(dst));
	if (ret != 11 || strcmp(dst, "hello world") != 0)
	{
		printf(RED "[FAIL] ft_strlcat -> basic append failed\n" RESET);
		success = 0;
	}
	memset(small, 'x', sizeof(small));
	memcpy(small, "abc", 4);
	ret = ft_strlcat(small, "defgh", 5);
	if (ret != 8 || memcmp(small, "abcd", 5) != 0)
	{
		printf(RED "[FAIL] ft_strlcat truncated -> wrong return or content\n"
			RESET);
		success = 0;
	}
	ret = ft_strlcat(small, "zzz", 2);
	if (ret != 2 + 3)
	{
		printf(RED "[FAIL] ft_strlcat size<=dstlen return value incorrect\n"
			RESET);
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_strlcat\n" RESET);
	else
		printf(RED "[FAIL] ft_strlcat\n" RESET);
	return (success);
}
