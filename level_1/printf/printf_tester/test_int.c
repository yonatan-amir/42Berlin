#include "../libftprintf/ft_printf.h"
#include "capture_output.h"
#include "test_runner.h"
#include <limits.h>

static int	run_int_case(const char *label, const char *fmt, int arg)
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
		printf(RED "%s printf/ft_printf mismatch\n" RESET, label);
		printf(RED "printf ret: %d | ft_printf ret: %d\n\n" RESET, r_printf,
			r_ft);
		return (0);
	}
	return (1);
}

int	test_int(void)
{
	const char	*fmt = "test:%d:test";
	int			ok;

	ok = 1;
	if (!run_int_case("123", fmt, 123))
		ok = 0;
	if (!run_int_case("-123", fmt, -123))
		ok = 0;
	if (!run_int_case("0", fmt, 0))
		ok = 0;
	if (!run_int_case("1", fmt, 1))
		ok = 0;
	if (!run_int_case("-1", fmt, -1))
		ok = 0;
	// edgecases
	if (!run_int_case("INT_MAX", fmt, INT_MAX))
		ok = 0;
	if (!run_int_case("INT_MIN", fmt, INT_MIN))
		ok = 0;
	if (!run_int_case("INT_MIN + 1", fmt, INT_MIN + 1))
		ok = 0;
	if (ok)
		printf(GREEN "TEST_INT [OK]\n\n" RESET);
	else
		printf(RED "TEST_INT [FAIL]\n\n" RESET);
	return (ok);
}
