#include "tests.h"
#include <stdio.h>

t_test	tests[] = {
	{"ft_strlen", test_ft_strlen},   {"ft_memset", test_ft_memset}, {"ft_bzero",
		test_ft_bzero},   {"ft_memcpy", test_ft_memcpy},   {"ft_memmove",
		test_ft_memmove}, {"ft_memchr", test_ft_memchr},   {"ft_memcmp",
		test_ft_memcmp}, {"ft_isalpha", test_ft_isalpha}, {"ft_isdigit",
		test_ft_isdigit}, {"ft_isalnum", test_ft_isalnum}, {"ft_isascii",
		test_ft_isascii}, {"ft_isprint", test_ft_isprint}, {"ft_strchr",
		test_ft_strchr},     {"ft_strrchr", test_ft_strrchr},
		      {"ft_strncmp", test_ft_strncmp},     {"ft_strlcpy",
		test_ft_strlcpy},       {"ft_strlcat", test_ft_strlcat},
	{"ft_strnstr", test_ft_strnstr}, {"ft_strdup", test_ft_strdup},
		{"ft_substr", test_ft_substr}, {"ft_strjoin", test_ft_strjoin},
		{"ft_tolower", test_ft_tolower}, {"ft_toupper", test_ft_toupper},
		{"ft_atoi", test_ft_atoi},     {"ft_calloc", test_ft_calloc},
		  {"ft_strtrim", test_ft_strtrim}, {"ft_split", test_ft_split},
		    {"ft_itoa", test_ft_itoa},       {"ft_strmapi", test_ft_strmapi},
		{"ft_striteri", test_ft_striteri}, {"ft_putchar_fd",
		test_ft_putchar_fd}, {"ft_putstr_fd", test_ft_putstr_fd},
		{"ft_putendl_fd", test_ft_putendl_fd}, {"ft_putnbr_fd",
		test_ft_putnbr_fd},
};

int	main(void)
{
	int	passed;
	int	total;
	int	i;

	i = 0;
	passed = 0;
	total = sizeof(tests) / sizeof(tests[0]);
	printf(YELLOW "------------------------------\n" RESET);
	while (i < total)
	{
		if (tests[i].fn())
		{
			passed++;
		}
		i++;
	}
	printf(YELLOW "------------------------------\n" RESET);
	printf(YELLOW "\n%d/%d tests passed\n" RESET, passed, total);
	return (passed == total ? 0 : 1);
}
