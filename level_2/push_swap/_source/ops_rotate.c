/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 13:09:40 by yamir             #+#    #+#             */
/*   Updated: 2026/03/30 13:09:40 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	rotate(t_stack *stack)
{
	t_node	*temp_a;

	temp_a = stack->head;
	stack->head = stack->head->next;
	stack->tail->next = temp_a;
	stack->tail = temp_a;
	temp_a->next = NULL;
}

void	ra(t_ps *wrapper)
{
	if (wrapper->a.size < 2)
		return ;
	rotate(&wrapper->a);
	write(1, "ra\n", 3);
}

void	rb(t_ps *wrapper)
{
	if (wrapper->b.size < 2)
		return ;
	rotate(&wrapper->b);
	write(1, "rb\n", 3);
}

void	rr(t_ps *wrapper)
{
	if (wrapper->a.size > 1)
		rotate(&wrapper->a);
	if (wrapper->b.size > 1)
		rotate(&wrapper->b);
	write(1, "rr\n", 3);
}
