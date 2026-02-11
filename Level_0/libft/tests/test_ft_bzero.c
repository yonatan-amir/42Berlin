#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>
#include <string.h>

int	test_ft_bzero(void)
{
	char	buf[6] = "hello";
	int		success;

	success = 1;
	ft_bzero(buf, 3);
	if (memcmp(buf, "\0\0\0lo", 5) != 0)
	{
		printf(RED "[FAIL] ft_bzero -> first 3 bytes not zeroed\n" RESET);
		success = 0;
	}
	buf[0] = 'x';
	ft_bzero(buf, 0);
	if (buf[0] != 'x')
	{
		printf(RED "[FAIL] ft_bzero size 0 should not change buffer\n" RESET);
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_bzero\n" RESET);
	else
		printf(RED "[FAIL] ft_bzero\n" RESET);
	return (success);
}
