#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>
#include <string.h>

int	test_ft_memset(void)
{
	char	buf[6] = "00000";
	int		success;
	void	*ret;

	success = 1;
	ret = ft_memset(buf, 'A', 5);
	if (ret != buf || memcmp(buf, "AAAAA", 5) != 0)
	{
		printf(RED "[FAIL] ft_memset -> did not fill buffer or wrong return\n"
			RESET);
		success = 0;
	}
	buf[0] = 'B';
	buf[1] = '\0';
	ret = ft_memset(buf, 'C', 0);
	if (ret != buf || buf[0] != 'B' || buf[1] != '\0')
	{
		printf(RED "[FAIL] ft_memset size 0 should be no-op with same pointer\n"
			RESET);
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_memset\n" RESET);
	else
		printf(RED "[FAIL] ft_memset\n" RESET);
	return (success);
}
