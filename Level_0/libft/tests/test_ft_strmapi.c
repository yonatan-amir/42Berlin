#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>
#include <string.h>

// clang-format off

static char	index_to_char(unsigned int i, char c)
{
	(void)c;
  return ('0' + i);
}

static char	to_upper_map(unsigned int i, char c)
{
    (void)i;
    return (ft_toupper(c));
}

int	test_ft_strmapi(void)
{
	int		success;
	char	*s;
	char	*res;

	success = 1;
	// Basic transform test
	s = "abc";
	res = ft_strmapi(s, to_upper_map);
	if (!res || strcmp(res, "ABC") != 0)
	{
		printf(RED "[FAIL] ft_strmapi basic uppercase -> expected \"ABC\", "
			"got \"%s\"\n" RESET, res ? res : NULL);
		success = 0;
	}
	free(res);
	
	//check index
	s = "abc";
	res = ft_strmapi(s, index_to_char);
	if (!res || strcmp(res, "012") != 0)
	{
		printf(RED "[FAIL] ft_strmapi prints index 012 -> expected \"012\", "
			"got \"%s\"\n" RESET, res ? res : NULL);
		success = 0;
	}
	free(res);
	//return NULL if string is NULL
	s = NULL;
	res = ft_strmapi(s, to_upper_map);
	if (res)
	{
		printf(RED "[FAIL] ft_strmapi invalid s-> expected \"NULL\", "
			"got \"%s\"\n" RESET, res ? res : NULL);
		success = 0;
	}
	//return NULL if fnc is NULL
	s = "abc";
	res = ft_strmapi(s, NULL);
	if (res)
	{
		printf(RED "[FAIL] ft_strmapi invalid function-> expected \"NULL\", "
			"got \"%s\"\n" RESET, res ? res : NULL);
		success = 0;
	}
		//If string is empty
	s = "";
	res = ft_strmapi(s, to_upper_map);
	if (!res || strcmp(res, "") != 0)
	{
		printf(RED "[FAIL] ft_strmapi empty string-> expected \"\", "
			"got \"%s\"\n" RESET, res ? res : NULL);
		success = 0;
	}
	free(res);
	if (success)
		printf(GREEN "[OK]   ft_strmapi\n" RESET);
	else
		printf(RED "[FAIL] ft_strmapi\n" RESET);
	return (success);
}
