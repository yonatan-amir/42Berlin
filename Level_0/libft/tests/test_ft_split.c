#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	free_split(char **res)
{
	for (int i = 0; res[i]; i++)
		free(res[i]);
	free(res);
}

int	test_ft_split(void)
{
	int		success;
	char	**res;
	char	buf[20] = {'h', 'e', 'l', 'l', 'o', '\0', 'w', 'o', 'r', 'l', 'd',
			'\0', 't', 'e', 's', 't', '\0'};

	success = 1;
	// ------------------------------
	// Basic test
	// ------------------------------
	res = ft_split("hello world test", ' ');
	if (!res)
	{
		printf(RED "[FAIL] ft_split -> returned NULL on basic test\n" RESET);
		return (0);
	}
	if (strcmp(res[0], "hello") != 0 || strcmp(res[1], "world") != 0
		|| strcmp(res[2], "test") != 0 || res[3] != NULL)
	{
		printf(RED "[FAIL] ft_split -> basic split incorrect\n" RESET);
		success = 0;
	}
	free_split(res);
	// ------------------------------
	// Empty string
	// ------------------------------
	res = ft_split("", ' ');
	if (!res || res[0] != NULL)
	{
		printf(RED "[FAIL] ft_split -> empty string edgecase\n" RESET);
		success = 0;
	}
	free(res);
	// ------------------------------
	// Only delimiters
	// ------------------------------
	res = ft_split("     ", ' ');
	if (!res || res[0] != NULL)
	{
		printf(RED "[FAIL] ft_split -> only delimiters edgecase\n" RESET);
		success = 0;
	}
	free(res);
	// ------------------------------
	// Leading + trailing delimiters
	// ------------------------------
	res = ft_split("   hello world   ", ' ');
	if (!res || strcmp(res[0], "hello") != 0 || strcmp(res[1], "world") != 0
		|| res[2] != NULL)
	{
		printf(RED "[FAIL] ft_split -> leading/trailing spaces\n" RESET);
		success = 0;
	}
	free_split(res);
	// ------------------------------
	// Multiple consecutive delimiters
	// ------------------------------
	res = ft_split("hello   world   test", ' ');
	if (!res || strcmp(res[0], "hello") != 0 || strcmp(res[1], "world") != 0
		|| strcmp(res[2], "test") != 0 || res[3] != NULL)
	{
		printf(RED "[FAIL] ft_split -> multiple delimiters\n" RESET);
		success = 0;
	}
	free_split(res);
	// ------------------------------
	// EDGE CASE: delimiter = '\0'
	// ------------------------------
	{
		res = ft_split(buf, '\0');
		// Expected behavior:
		// ft_split should treat '\0' as "end of string", NOT a delimiter.
		// So the only visible string is "hello".
		if (!res || strcmp(res[0], "hello") != 0 || res[1] != NULL)
		{
			printf(RED "[FAIL] -> delimiter '\\0' behavior incorrect\n" RESET);
			success = 0;
		}
		free_split(res);
	}
	// ------------------------------
	// Single word
	// ------------------------------
	res = ft_split("hello", ' ');
	if (!res || strcmp(res[0], "hello") != 0 || res[1] != NULL)
	{
		printf(RED "[FAIL] ft_split -> single word\n" RESET);
		success = 0;
	}
	free_split(res);
	// ------------------------------
	// Delimiter not found
	// ------------------------------
	res = ft_split("hello", ',');
	if (!res || strcmp(res[0], "hello") != 0 || res[1] != NULL)
	{
		printf(RED "[FAIL] ft_split -> delimiter not found\n" RESET);
		success = 0;
	}
	free_split(res);
	// ------------------------------
	// String starting AND ending with delimiter
	// ------------------------------
	res = ft_split("_hello_world_", '_');
	if (!res || strcmp(res[0], "hello") != 0 || strcmp(res[1], "world") != 0
		|| res[2] != NULL)
	{
		printf(RED "[FAIL] ft_split -> start+end delimiters\n" RESET);
		success = 0;
	}
	free_split(res);
	// ------------------------------
	// NULL input (should return NULL)
	// ------------------------------
	res = ft_split(NULL, ' ');
	if (res != NULL)
	{
		printf(RED " ft_split-> should return (NULL on NULL input\n" RESET);
		success = 0;
	}
	// Final result
	if (success)
		printf(GREEN "[OK]   ft_split\n" RESET);
	else
		printf(RED "[FAIL] ft_split\n" RESET);
	return (success);
}
