#include "../_source/ft_printf.h"
#include "capture_output.h"
#include "test_runner.h"
#include <limits.h>

static int	run_x_case(const char *label, const char *fmt, unsigned int arg)
{
	char	buffer_printf[128];
	char	buffer_ft[128];
	int		r_printf;
	int		r_ft;

	r_printf = capture_output_x(printf, fmt, buffer_printf,
			sizeof(buffer_printf), arg);
	r_ft = capture_output_x(ft_printf, fmt, buffer_ft, sizeof(buffer_ft),
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

int	test_x(void)
{
	const char	*fmt_plain = "%x";
	const char	*fmt_text = "test:%x:end";
	const char	*fmt_pct = "%% %x %% ";
	int			ok;

	ok = 1;
	if (!run_x_case("0", fmt_plain, 0))
		ok = 0;
	if (!run_x_case("1", fmt_plain, 1))
		ok = 0;
	if (!run_x_case("9", fmt_plain, 9))
		ok = 0;
	if (!run_x_case("10", fmt_plain, 10))
		ok = 0;
	if (!run_x_case("15", fmt_plain, 15))
		ok = 0;
	if (!run_x_case("16", fmt_plain, 16))
		ok = 0;
	if (!run_x_case("31", fmt_plain, 31))
		ok = 0;
	if (!run_x_case("255", fmt_plain, 255))
		ok = 0;
	if (!run_x_case("256", fmt_plain, 256))
		ok = 0;
	if (!run_x_case("UINT_MAX", fmt_plain, UINT_MAX))
		ok = 0;
	if (!run_x_case("text 26", fmt_text, 26))
		ok = 0;
	if (!run_x_case("text 255", fmt_text, 255))
		ok = 0;
	if (!run_x_case("percent 42", fmt_pct, 42))
		ok = 0;
	if (ok)
		printf(GREEN "TEST_X [OK]\n\n" RESET);
	else
		printf(RED "TEST_X [FAIL]\n\n" RESET);
	return (ok);
}
