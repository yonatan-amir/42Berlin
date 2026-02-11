#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	test_ft_strdup(void)
{
	int		success;
	char	*dup;
	char	src[] = "sample";

	success = 1;
	dup = ft_strdup(src);
	if (!dup || strcmp(dup, src) != 0)
	{
		printf(RED "[FAIL] ft_strdup -> copy mismatch or NULL\n" RESET);
		free(dup);
		return (0);
	}
	dup[0] = 'X';
	if (src[0] != 's')
	{
		printf(RED "[FAIL] ft_strdup -> copy not independent from source\n"
			RESET);
		success = 0;
	}
	free(dup);
	dup = ft_strdup("");
	if (!dup || dup[0] != '\0')
	{
		printf(RED "[FAIL] ft_strdup -> empty string duplication failed\n"
			RESET);
		success = 0;
	}
	free(dup);
	if (success)
		printf(GREEN "[OK]   ft_strdup\n" RESET);
	else
		printf(RED "[FAIL] ft_strdup\n" RESET);
	return (success);
}
