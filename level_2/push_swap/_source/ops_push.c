/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:55:59 by yoyo              #+#    #+#             */
/*   Updated: 2026/03/11 12:56:40 by yoyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	push(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = stack_b->head;
	stack_b->head = stack_b->head->next;
	stack_b->size--;
	if (stack_b->size == 0)
		stack_b->tail = NULL;
	stack_a->size++;
	if (stack_a->size > 1)
	{
		temp_b = stack_a->head;
		stack_a->head = temp_a;
		temp_a->next = temp_b;
		return ;
	}
	stack_a->head = temp_a;
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
