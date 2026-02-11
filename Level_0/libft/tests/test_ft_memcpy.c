#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>
#include <string.h>

int	test_ft_memcpy(void)
{
	char	src[6] = "world";
	char	dst[6] = "hello";
	int		success;

	success = 1;
	ft_memcpy(dst, src, 5);
	if (memcmp(dst, "world", 5) != 0)
	{
		printf(RED "[FAIL] ft_memcpy -> basic copy failed\n" RESET);
		success = 0;
	}
	dst[0] = 'x';
	dst[1] = 'y';
	ft_memcpy(dst, src, 0);
	if (dst[0] != 'x' || dst[1] != 'y')
	{
		printf(RED "[FAIL] ft_memcpy size 0 should not change dst\n" RESET);
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_memcpy\n" RESET);
	else
		printf(RED "[FAIL] ft_memcpy\n" RESET);
	return (success);
}
