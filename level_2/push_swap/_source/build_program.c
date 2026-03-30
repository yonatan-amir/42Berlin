/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 13:08:06 by yamir             #+#    #+#             */
/*   Updated: 2026/03/30 13:08:06 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

int	build_program(t_ps *wrapper, int *nums, int count)
{
	int		i;
	t_node	*node;

	if (!nums)
		return (1);
	node = new_node(nums[0]);
	if (!node)
		return (1);
	wrapper->a.head = node;
	wrapper->a.tail = node;
	wrapper->a.size = 1;
	i = 1;
	while (i < count)
	{
		node = new_node(nums[i]);
		if (!node)
			return (clean_program(wrapper), 1);
		wrapper->a.tail->next = node;
		wrapper->a.tail = node;
		wrapper->a.size++;
		i++;
	}
	return (0);
}
