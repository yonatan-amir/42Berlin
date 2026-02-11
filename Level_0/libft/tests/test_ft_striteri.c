#include "../libft/libft.h"
#include "tests.h"
#include <stdio.h>
#include <string.h>

// clang-format off

static void	to_upper(unsigned int i, char *c)
{
    (void)i;
    *c = ft_toupper(*c);
}
static void	to_index(unsigned int i, char *c)
{
   *c = ('0' + i);
}

int	test_ft_striteri(void)
{
	int		success;
	char	*s;

	success = 1;
	// Basic transform test
  s = strdup("abc");
	ft_striteri(s, to_upper);
	if (!s || strcmp(s, "ABC") != 0)
	{
		printf(RED "[FAIL] ft_striteri basic uppercase -> expected \"ABC\", "
			"got \"%s\"\n" RESET, s ? s : NULL);
		success = 0;
	}
  free(s);
	
	//check index
  s = strdup("abc");
	ft_striteri(s, to_index);
	if (!s || strcmp(s, "012") != 0)
	{
		printf(RED "[FAIL] ft_striteri prints index 012 -> expected \"012\", "
			"got \"%s\"\n" RESET, s ? s : NULL);
		success = 0;
	}
  free(s);
	//return NULL if string is NULL
  s = NULL;
	ft_striteri(s, to_upper);
	//return NULL if fnc is NULL
  s = strdup("abc");
	ft_striteri(s, NULL);
		//If string is empty
  s = strdup("");
	ft_striteri(s, to_upper);
	if (!s || strcmp(s, "") != 0)
	{
		printf(RED "[FAIL] ft_striteri empty string-> expected \"\", "
			"got \"%s\"\n" RESET, s ? s : NULL);
		success = 0;
	}
  free(s);
	if (success)
		printf(GREEN "[OK]   ft_striteri\n" RESET);
	else
		printf(RED "[FAIL] ft_striteri\n" RESET);
	return (success);
}
