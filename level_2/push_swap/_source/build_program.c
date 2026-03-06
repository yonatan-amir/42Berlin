/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:14:42 by yoyo              #+#    #+#             */
/*   Updated: 2026/03/06 14:20:20 by yoyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	build_program(t_ps *wrapper, int *nums, int count)
{
	int		i;
	t_node	*node;

	if (!nums)
		return (1);
	node = malloc(sizeof(t_node));
	if (!node)
		return (clean_program(wrapper), 1);
	node->value = nums[0];
	node->next = NULL;
	wrapper->a.head = node;
	wrapper->a.tail = node;
	wrapper->a.size = 1;
	i = 1;
	while (i < count)
	{
		node = malloc(sizeof(t_node));
		if (!node)
			return (clean_program(wrapper), 1);
		node->value = nums[i];
		node->next = NULL;
		wrapper->a.tail->next = node;
		wrapper->a.tail = node;
		wrapper->a.size++;
		i++;
	}
	return (0);
}
