#include "../libftprintf/ft_printf.h"
#include "capture_output.h"
#include "test_runner.h"
#include <stdlib.h>

static int	run_ptr_case(const char *label, const char *fmt, void *arg)
{
	char	buffer_printf[512];
	char	buffer_ft[512];
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
		printf("%s printf/ft_printf mismatch\n", label);
		printf("printf ret: %d | ft_printf ret: %d\n\n", r_printf, r_ft);
		return (0);
	}
	return (1);
}

int	test_ptr(void)
{
	const char	*fmt = "test:%p";
	int			ok;
	void		*p_stack;
	int			x;
	char		*p_lit;
	void		*p_heap;

	p_heap = malloc(1);
	if (p_heap == NULL)
	{
		printf(RED "malloc Failed\n" RESET);
		return (0);
	}
	p_lit = "hi";
	x = 42;
	p_stack = &x;
	ok = 1;
	if (!run_ptr_case("NULL", fmt, NULL))
		ok = 0;
	if (!run_ptr_case("P_STACK", fmt, p_stack))
		ok = 0;
	if (!run_ptr_case("P_LIT", fmt, p_lit))
		ok = 0;
	if (!run_ptr_case("P_HEAP", fmt, p_heap))
		ok = 0;
	free(p_heap);
	if (ok)
		printf(GREEN "TEST_POINTER [OK]\n\n" RESET);
	else
		printf(RED "TEST_POINTER [FAIL]\n\n" RESET);
	return (ok);
}
