/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 13:09:44 by yamir             #+#    #+#             */
/*   Updated: 2026/03/30 13:09:44 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	swap(t_stack *stack)
{
	t_node	*temp_a;
	t_node	*temp_b;
	t_node	*temp_c;

	temp_a = stack->head;
	temp_b = stack->head->next;
	temp_c = temp_b->next;
	stack->head = temp_b;
	stack->head->next = temp_a;
	temp_a->next = temp_c;
}

void	sa(t_ps *wrapper)
{
	if (wrapper->a.size < 2)
		return ;
	swap(&wrapper->a);
	write(1, "sa\n", 3);
}

void	sb(t_ps *wrapper)
{
	if (wrapper->b.size < 2)
		return ;
	swap(&wrapper->b);
	write(1, "sb\n", 3);
}

void	ss(t_ps *wrapper)
{
	if (wrapper->a.size > 1)
		swap(&wrapper->a);
	if (wrapper->b.size > 1)
		swap(&wrapper->b);
	write(1, "ss\n", 3);
}
