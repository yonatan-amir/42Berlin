#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>
#include <string.h>

int	test_ft_memmove(void)
{
	char	buf1[12] = "hello world";
	char	buf2[14] = "overlap test";
	int		success;

	success = 1;
	// Non-overlapping copy
	ft_memmove(buf1, "abcdef", 7);
	if (strcmp(buf1, "abcdef") != 0)
	{
		printf(RED "[FAIL] ft_memmove -> non-overlap copy failed\n" RESET);
		success = 0;
	}
	// Overlap: dest > src
	ft_memmove(buf2 + 2, buf2, 5);
	if (strcmp(buf2, "ovoverl test") != 0)
	{
		printf(RED "[FAIL] ft_memmove -> overlap dest>src wrong result\n" RESET);
		success = 0;
	}
	// Overlap: dest < src
	memcpy(buf2, "123456789", 10);
	ft_memmove(buf2, buf2 + 2, 5);
	if (memcmp(buf2, "34567", 5) != 0)
	{
		printf(RED "[FAIL] ft_memmove -> overlap dest<src wrong result\n" RESET);
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_memmove\n" RESET);
	else
		printf(RED "[FAIL] ft_memmove\n" RESET);
	return (success);
}
