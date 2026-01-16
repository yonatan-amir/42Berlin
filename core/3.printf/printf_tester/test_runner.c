
#include "test_runner.h"

t_test_case	g_test_cases[] = {
	{"literal", test_literal},
	{"percent", test_percent},
	{"char", test_char},
	{"string", test_string},
	{"int", test_int},
	{"ptr", test_ptr},
	{"u", test_u},
	{"x", test_x},
	{"X", test_upperx},
};

int	main(void)
{
	int	passed;
	int	total;
	int	i;

	i = 0;
	passed = 0;
	total = sizeof(g_test_cases) / sizeof(g_test_cases[0]);
	printf(YELLOW "------------------------------\n" RESET);
	while (i < total)
	{
		if (g_test_cases[i].run())
		{
			passed++;
		}
		i++;
	}
	printf(YELLOW "------------------------------\n" RESET);
	printf(YELLOW "\n%d/%d tests passed\n" RESET, passed, total);
	return (passed == total ? 0 : 1);
}
