#include "../libft/libft.h"
#include "tests.h"
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size);

int	test_ft_calloc(void)
{
	int		success;
	int		*arr;
	size_t	huge;
	int		i;

	success = 1;
	arr = ft_calloc(5, sizeof(int));
	if (!arr)
	{
		printf(RED "[FAIL] ft_calloc-> returned NULL for small allocation\n" RESET);
		return (0);
	}
	i = 0;
	while (i < 5)
	{
		if (arr[i] != 0)
		{
			printf(RED "[FAIL] ft_calloc-> memory not zeroed at index%d\n" RESET,
				i);
			success = 0;
			break ;
		}
		i++;
	}
	free(arr);
	huge = SIZE_MAX / 2 + 1;
	arr = ft_calloc(huge, 2);
	if (arr != NULL)
	{
		printf(RED "[FAIL] ft_calloc-> should return (NULL on overflow guard\n" RESET);
		free(arr);
		success = 0;
	}
	if (success)
		printf(GREEN "[OK]   ft_calloc\n" RESET);
	else
		printf(RED "[FAIL] ft_calloc\n" RESET);
	return (success);
}
