#include "../libftprintf/ft_printf.h"
#include "capture_output.h"
#include "test_runner.h"

static int	run_string_case(const char *label, const char *fmt, const char *arg)
{
	char	buffer_printf[512];
	char	buffer_ft[512];
	int		r_printf;
	int		r_ft;

	r_printf = capture_output_str(printf, fmt, buffer_printf,
			sizeof(buffer_printf), arg);
	r_ft = capture_output_str(ft_printf, fmt, buffer_ft, sizeof(buffer_ft),
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

int	test_string(void)
{
	const char	*fmt = "test%s";
	int			ok;

	ok = 1;
	if (!run_string_case("Testing", fmt, "Testing"))
		ok = 0;
	if (!run_string_case("NUL", fmt, NULL))
		ok = 0;
	if (!run_string_case("NUL", fmt, ""))
		ok = 0;
	if (!run_string_case("NUL",
							fmt,
							"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
							"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"))
		ok = 0;
	if (ok)
		printf(GREEN "TEST_STRING [OK]\n\n" RESET);
	else
		printf(RED "TEST_STRING [FAIL]\n\n" RESET);
	return (ok);
}
