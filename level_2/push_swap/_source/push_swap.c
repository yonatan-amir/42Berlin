#include "ft_printf/libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

static int	error_exit(t_ps *wrapper, int *nums)
{
	clean_program(wrapper);
	free(nums);
	ft_putstr_fd("Error\n", 2);
	return (1);
}

int	main(int const argc, char **argv)
{
	t_ps	wrapper;
	int		*nums;
	int		count;
	int		status;

	ft_bzero(&wrapper, sizeof(t_ps));
	nums = NULL;
	count = 0;
	if (argc == 1)
		return (0);
	status = parser(&nums, &count, argc, argv);
	if (status != 0)
		return (error_exit(&wrapper, nums));
	status = build_program(&wrapper, nums, count);
	free(nums);
	if (status != 0)
		return (error_exit(&wrapper, NULL));
	if (sort(&wrapper) != 0)
		return (error_exit(&wrapper, NULL));
	clean_program(&wrapper);
	return (0);
}
