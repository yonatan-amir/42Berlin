#include "../libftprintf/ft_printf.h"
#include "capture_output.h"
#include "test_runner.h"

static int	run_noarg_case(const char *label, const char *fmt)
{
	char	buffer_printf[128];
	char	buffer_ft[128];
	int		r_printf;
	int		r_ft;

	r_printf = capture_output(printf, fmt, buffer_printf,
			sizeof(buffer_printf));
	r_ft = capture_output(ft_printf, fmt, buffer_ft, sizeof(buffer_ft));
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

static int	run_uint_case(const char *label, const char *fmt, unsigned int arg)
{
	char	buffer_printf[128];
	char	buffer_ft[128];
	int		r_printf;
	int		r_ft;

	r_printf = capture_output_u(printf, fmt, buffer_printf,
			sizeof(buffer_printf), arg);
	r_ft = capture_output_u(ft_printf, fmt, buffer_ft, sizeof(buffer_ft),
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

static int	run_str_case(const char *label, const char *fmt, const char *arg)
{
	char	buffer_printf[256];
	char	buffer_ft[256];
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
		printf(RED "%s printf/ft_printf mismatch\n" RESET, label);
		printf(RED "printf ret: %d | ft_printf ret: %d\n\n" RESET, r_printf,
			r_ft);
		return (0);
	}
	return (1);
}

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
		printf(RED "%s printf/ft_printf mismatch\n" RESET, label);
		printf(RED "printf ret: %d | ft_printf ret: %d\n\n" RESET, r_printf,
			r_ft);
		return (0);
	}
	return (1);
}

static int	run_ptr_case(const char *label, const char *fmt, void *arg)
{
	char	buffer_printf[256];
	char	buffer_ft[256];
	int		r_printf;
	int		r_ft;

	r_printf = capture_output_ptr(printf, fmt, buffer_printf,
			sizeof(buffer_printf), arg);
	r_ft = capture_output_ptr(ft_printf, fmt, buffer_ft, sizeof(buffer_ft),
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

int	test_bonus(void)
{
	int		ok;
	int		x;
	void	*p;

	ok = 1;
	x = 42;
	p = &x;
	ok &= run_int_case("d width", "%5d", 42);
	ok &= run_int_case("d left", "%-5d", 42);
	ok &= run_int_case("d zero", "%05d", 42);
	ok &= run_int_case("d zero neg", "%05d", -42);
	ok &= run_int_case("d prec", "%.3d", 42);
	ok &= run_int_case("d prec zero", "%.0d", 0);
	ok &= run_int_case("d width prec", "%8.3d", 42);
	ok &= run_int_case("d plus", "%+d", 42);
	ok &= run_int_case("d space", "% d", 42);
	ok &= run_int_case("d plus space", "%+ d", 42);
	ok &= run_int_case("i width", "%5i", -42);
	ok &= run_int_case("i prec", "%.3i", 7);
	ok &= run_uint_case("u width", "%5u", 42);
	ok &= run_uint_case("u zero", "%05u", 42);
	ok &= run_uint_case("u prec", "%.3u", 42);
	ok &= run_uint_case("u width prec", "%8.3u", 42);
	ok &= run_uint_case("x width", "%5x", 0x2a);
	ok &= run_uint_case("x left", "%-5x", 0x2a);
	ok &= run_uint_case("x zero", "%05x", 0x2a);
	ok &= run_uint_case("x prec", "%.3x", 0x2a);
	ok &= run_uint_case("x prec zero", "%.0x", 0);
	ok &= run_uint_case("x width prec", "%8.3x", 0x2a);
	ok &= run_uint_case("x sharp zero", "%#x", 0);
	ok &= run_uint_case("x sharp", "%#x", 0x2a);
	ok &= run_uint_case("x sharp width", "%#8x", 0x2a);
	ok &= run_uint_case("X width", "%5X", 0x2a);
	ok &= run_uint_case("X zero", "%05X", 0x2a);
	ok &= run_uint_case("X prec", "%.3X", 0x2a);
	ok &= run_uint_case("X sharp", "%#X", 0x2a);
	ok &= run_uint_case("X sharp width", "%#8X", 0x2a);
	ok &= run_str_case("s width", "%5s", "hi");
	ok &= run_str_case("s left", "%-5s", "hi");
	ok &= run_str_case("s zero", "%05s", "hi");
	ok &= run_str_case("s prec", "%.3s", "hello");
	ok &= run_str_case("s width prec", "%8.3s", "hi");
	ok &= run_char_case("c width", "%5c", 'A');
	ok &= run_char_case("c left", "%-5c", 'A');
	ok &= run_char_case("c zero", "%05c", 'A');
	ok &= run_char_case("c prec", "%.3c", 'A');
	ok &= run_ptr_case("p width", "%20p", p);
	ok &= run_ptr_case("p left", "%-20p", p);
	ok &= run_ptr_case("p zero", "%020p", p);
	ok &= run_ptr_case("p prec null", "%.0p", NULL);
	ok &= run_ptr_case("p prec", "%.5p", p);
	ok &= run_noarg_case("percent width", "%5%");
	ok &= run_noarg_case("percent left", "%-5%");
	ok &= run_noarg_case("percent zero", "%05%");
	if (ok)
		printf(GREEN "TEST_BONUS [OK]\n\n" RESET);
	else
		printf(RED "TEST_BONUS [FAIL]\n\n" RESET);
	return (ok);
}
