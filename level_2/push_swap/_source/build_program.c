/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:14:42 by yoyo              #+#    #+#             */
/*   Updated: 2026/03/09 16:09:49 by yoyo             ###   ########.fr       */
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
