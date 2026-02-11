#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>

int	test_ft_isascii(void)
{
	int	success;

	success = 1;
	// Valid ASCII (should be 1)
	if (ft_isascii(0) != 1)
	{
		printf(RED "[FAIL] ft_isascii(0) -> expected 1, got %d\n" RESET,
			ft_isascii(0));
		success = 0;
	}
	if (ft_isascii('A') != 1)
	{
		printf(RED "[FAIL] ft_isascii('A') -> expected 1, got %d\n" RESET,
			ft_isascii('A'));
		success = 0;
	}
	if (ft_isascii('z') != 1)
	{
		printf(RED "[FAIL] ft_isascii('z') -> expected 1, got %d\n" RESET,
			ft_isascii('z'));
		success = 0;
	}
	if (ft_isascii(127) != 1)
	{
		printf(RED "[FAIL] ft_isascii(127) -> expected 1, got %d\n" RESET,
			ft_isascii(127));
		success = 0;
	}
	// Invalid ASCII (should be 0)
	if (ft_isascii(-1) != 0)
	{
		printf(RED "[FAIL] ft_isascii(-1) -> expected 0, got %d\n" RESET,
			ft_isascii(-1));
		success = 0;
	}
	if (ft_isascii(128) != 0)
	{
		printf(RED "[FAIL] ft_isascii(128) -> expected 0, got %d\n" RESET,
			ft_isascii(128));
		success = 0;
	}
	if (ft_isascii(200) != 0)
	{
		printf(RED "[FAIL] ft_isascii(200) -> expected 0, got %d\n" RESET,
			ft_isascii(200));
		success = 0;
	}
	if (ft_isascii(999) != 0)
	{
		printf(RED "[FAIL] ft_isascii(999) -> expected 0, got %d\n" RESET,
			ft_isascii(999));
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_isascii\n" RESET);
	else
		printf(RED "[FAIL] ft_isascii\n" RESET);
	return (success);
}
