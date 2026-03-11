/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:14:59 by yoyo              #+#    #+#             */
/*   Updated: 2026/03/09 16:26:01 by yoyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

static void	assign_index(t_ps *wrapper)
{
	t_node	*temp_a;
	t_node	*temp_b;
	int		counter;

	temp_a = wrapper->a.head;
	while (temp_a)
	{
		counter = 0;
		temp_b = wrapper->a.head;
		while (temp_b)
		{
			if (temp_a->value > temp_b->value)
				counter++;
			temp_b = temp_b->next;
		}
		temp_a->index = counter;
		temp_a = temp_a->next;
	}
}

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

	nums = NULL;
	count = 0;
	status = init_program(&wrapper);
	if (status != 0)
		return (error_exit(&wrapper, nums));
	if (argc == 1)
		return (0);
	status = parser(&nums, &count, argc, argv);
	if (status != 0)
		return (error_exit(&wrapper, nums));
	status = build_program(&wrapper, nums, count);
	free(nums);
	if (status != 0)
		return (error_exit(&wrapper, NULL));
	assign_index(&wrapper);
	if (sort(&wrapper) != 0)
		return (error_exit(&wrapper, NULL));
	clean_program(&wrapper);
	return (0);
}
