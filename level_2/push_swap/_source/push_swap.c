#include "ft_printf/libft/libft.h"
#include "push_swap.h"

int	main(int const argc, char *argv[])
{
	t_ps wrapper = {};

	if (argc == 1)
		return (0);
	if (init_program(&wrapper, argc, argv) != 0)
	{
		clean_program(&wrapper);
		return (ft_putstr_fd("Error\n", 2), 1);
	}
	if (sort(&wrapper) != 0)
	{
		clean_program(&wrapper);
		return (ft_putstr_fd("Error\n", 2), 1);
	}
	clean_program(&wrapper);
	return (0);
}