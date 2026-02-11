#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>
#include <string.h>

int	test_ft_memchr(void)
{
	const char	data[] = {1, 2, 3, 4, 5, 0};
	int			success;
	const void	*res;

	success = 1;
	res = ft_memchr(data, 3, sizeof(data));
	if (res != data + 2)
	{
		printf(RED "[FAIL] ft_memchr -> expected pointer to index 2\n" RESET);
		success = 0;
	}
	res = ft_memchr(data, 6, sizeof(data));
	if (res != NULL)
	{
		printf(RED "[FAIL] ft_memchr -> expected NULL when not found\n" RESET);
		success = 0;
	}
	res = ft_memchr(data, 1, 0);
	if (res != NULL)
	{
		printf(RED "[FAIL] ft_memchr n=0 should return NULL\n" RESET);
		success = 0;
	}
	{
		char	buf[] = "abc\0def";

		res = ft_memchr(buf, '\0', sizeof(buf));
		if (res != (void *)(buf + 3))
		{
			printf(RED "[FAIL] ft_memchr -> should find '\\0' within range\n"
				RESET);
			success = 0;
		}
	}
	if (success)
		printf(GREEN "[OK]   ft_memchr\n" RESET);
	else
		printf(RED "[FAIL] ft_memchr\n" RESET);
	return (success);
}
