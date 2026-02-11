#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>

int	test_ft_isprint(void)
{
	int	success;

	success = 1;
	// Printable characters (should be 1)
	if (ft_isprint(' ') != 1) // space = 32
	{
		printf(RED "[FAIL] ft_isprint(' ') -> expected 1, got %d\n" RESET,
			ft_isprint(' '));
		success = 0;
	}
	if (ft_isprint('A') != 1)
	{
		printf(RED "[FAIL] ft_isprint('A') -> expected 1, got %d\n" RESET,
			ft_isprint('A'));
		success = 0;
	}
	if (ft_isprint('z') != 1)
	{
		printf(RED "[FAIL] ft_isprint('z') -> expected 1, got %d\n" RESET,
			ft_isprint('z'));
		success = 0;
	}
	if (ft_isprint('0') != 1)
	{
		printf(RED "[FAIL] ft_isprint('0') -> expected 1, got %d\n" RESET,
			ft_isprint('0'));
		success = 0;
	}
	if (ft_isprint('~') != 1) // last printable ASCII
	{
		printf(RED "[FAIL] ft_isprint('~') -> expected 1, got %d\n" RESET,
			ft_isprint('~'));
		success = 0;
	}
	// Non-printable characters (should be 0)
	if (ft_isprint('\n') != 0)
	{
		printf(RED "[FAIL] ft_isprint('\\n') -> expected 0, got %d\n" RESET,
			ft_isprint('\n'));
		success = 0;
	}
	if (ft_isprint('\t') != 0)
	{
		printf(RED "[FAIL] ft_isprint('\\t') -> expected 0, got %d\n" RESET,
			ft_isprint('\t'));
		success = 0;
	}
	if (ft_isprint('\0') != 0)
	{
		printf(RED "[FAIL] ft_isprint('\\0') -> expected 0, got %d\n" RESET,
			ft_isprint('\0'));
		success = 0;
	}
	if (ft_isprint(31) != 0) // last non-printable before ' '
	{
		printf(RED "[FAIL] ft_isprint(31) -> expected 0, got %d\n" RESET,
			ft_isprint(31));
		success = 0;
	}
	if (ft_isprint(127) != 0) // DEL = non-printable
	{
		printf(RED "[FAIL] ft_isprint(127) -> expected 0, got %d\n" RESET,
			ft_isprint(127));
		success = 0;
	}
	if (ft_isprint(128) != 0)
	{
		printf(RED "[FAIL] ft_isprint(128) -> expected 0, got %d\n" RESET,
			ft_isprint(128));
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_isprint\n" RESET);
	else
		printf(RED "[FAIL] ft_isprint\n" RESET);
	return (success);
}
