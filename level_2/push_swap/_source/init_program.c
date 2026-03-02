#include "push_swap.h"
#include <stdlib.h>

int	init_program(t_ps *wrapper, int argc, char **argv)
{
	int	count;
	int	*nums;
	int	status;

	(void)wrapper;
	count = 0;
	nums = NULL;
	if (argc < 2)
		return (0);
	status = parser(&nums, &count, argc, argv);
	free(nums);
	return (status);
}
