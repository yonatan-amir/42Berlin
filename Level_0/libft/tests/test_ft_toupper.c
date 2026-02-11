#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>

int	test_ft_toupper(void)
{
	int	success;

	success = 1;
	if (ft_toupper('a') != 'A')
	{
		printf(RED "[FAIL] ft_toupper('a') -> expected 'A'\n" RESET);
		success = 0;
	}
	if (ft_toupper('z') != 'Z')
	{
		printf(RED "[FAIL] ft_toupper('z') -> expected 'Z'\n" RESET);
		success = 0;
	}
	if (ft_toupper('1') != '1' || ft_toupper('$') != '$')
	{
		printf(RED "[FAIL] ft_toupper non-alpha should be unchanged\n" RESET);
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_toupper\n" RESET);
	else
		printf(RED "[FAIL] ft_toupper\n" RESET);
	return (success);
}
