#include "../_source/ft_printf.h"
#include "capture_output.h"
#include "test_runner.h"

static int	run_char_case(const char *label, const char *fmt, int arg)
{
	char	buffer_printf[128];
	char	buffer_ft[128];
	int		r_printf;
	int		r_ft;

	r_printf = capture_output_char(printf, fmt, buffer_printf,
			sizeof(buffer_printf), arg);
	r_ft = capture_output_char(ft_printf, fmt, buffer_ft, sizeof(buffer_ft),
			arg);
	if (r_ft == -1 || r_printf == -1)
	{
		printf(RED "capture output failed\n" RESET);
		return (0);
	}
	if (r_printf != r_ft || memcmp(buffer_printf, buffer_ft, r_printf) != 0)
	{
		printf("%s printf/ft_printf mismatch\n", label);
		printf("printf ret: %d | ft_printf ret: %d\n\n", r_printf, r_ft);
		return (0);
	}
	return (1);
}

int	test_char(void)
{
	const char	*fmt = "test%c";
	int			ok;

	ok = 1;
	if (!run_char_case("A", fmt, 'A'))
		ok = 0;
	if (!run_char_case("NUL", fmt, '\0'))
		ok = 0;
	if (ok)
		printf(GREEN "TEST_CHAR [OK]\n\n" RESET);
	else
		printf(RED "TEST_CHAR [FAIL]\n\n" RESET);
	return (ok);
}
