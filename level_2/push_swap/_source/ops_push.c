/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 13:09:31 by yamir             #+#    #+#             */
/*   Updated: 2026/03/30 13:09:32 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	push(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	temp = stack_b->head;
	stack_b->head = stack_b->head->next;
	stack_b->size--;
	if (stack_b->size == 0)
		stack_b->tail = NULL;
	temp->next = stack_a->head;
	stack_a->head = temp;
	stack_a->size++;
	if (stack_a->size == 1)
		stack_a->tail = stack_a->head;
}

void	pa(t_ps *wrapper)
{
	if (wrapper->b.size == 0)
		return ;
	push(&wrapper->a, &wrapper->b);
	write(1, "pa\n", 3);
}

void	pb(t_ps *wrapper)
{
	if (wrapper->a.size == 0)
		return ;
	push(&wrapper->b, &wrapper->a);
	write(1, "pb\n", 3);
}
