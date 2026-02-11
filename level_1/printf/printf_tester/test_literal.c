#include "../libftprintf/ft_printf.h"
#include "capture_output.h"
#include "test_runner.h"

int	test_literal(void)
{
	int			success;
	const char	*str = "string_compare";
	char		buffer_printf[128];
	char		buffer_ft[128];
	int			r_printf;
	int			r_ft;

	success = 1;
	r_printf = capture_output(printf, str, buffer_printf,
			sizeof(buffer_printf));
	r_ft = capture_output(ft_printf, str, buffer_ft, sizeof(buffer_ft));
	if (r_ft == -1 || r_printf == -1)
	{
		success = 0;
		printf(RED "capture output failed\n" RESET);
	}
	if (r_printf != r_ft || strcmp(buffer_printf, buffer_ft) != 0)
		success = 0;
	if (!success)
	{
		printf("EXPECTED string to be equal to %s but output was %s \n\n", str,
			buffer_ft);
		if (r_printf != r_ft)
			printf("EXPECTED %d to be equal to %d\n\n", r_printf, r_ft);
	}
	if (success)
		printf(GREEN "TEST_LITERAL [OK]\n\n" RESET);
	else
		printf(RED "TEST_LITERAL [FAIL]\n\n" RESET);
	return (success);
}
