/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_r_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:21:39 by yoyo              #+#    #+#             */
/*   Updated: 2026/03/09 15:50:32 by yoyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	rotate(t_stack *stack)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = stack->tail;
	temp_b = stack->head;
	while (temp_b->next != stack->tail)
		temp_b = temp_b->next;
	temp_b->next = NULL;
	temp_a->next = stack->head;
	stack->head = temp_a;
	stack->tail = temp_b;
}

void	rra(t_ps *wrapper)
{
	if (wrapper->a.size < 2)
		return ;
	rotate(&wrapper->a);
	write(1, "rra\n", 4);
}

void	rrb(t_ps *wrapper)
{
	if (wrapper->b.size < 2)
		return ;
	rotate(&wrapper->b);
	write(1, "rrb\n", 4);
}

void	rrr(t_ps *wrapper)
{
	if (wrapper->a.size > 1)
		rotate(&wrapper->a);
	if (wrapper->b.size > 1)
		rotate(&wrapper->b);
	write(1, "rrr\n", 4);
}