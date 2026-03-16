/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:10:11 by yoyo              #+#    #+#             */
/*   Updated: 2026/03/16 21:04:13 by yoyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_cost(int pos, int size)
{
	if (pos <= size - pos)
		return (pos);
	return (size - pos);
}

int	get_target_pos(t_stack stack_a, int index)
{
	t_node	*curr;
	t_node	*next;
	int		pos;

	if (!stack_a.head)
		return (0);
	if (!stack_a.head->next)
		return (0);
	curr = stack_a.head;
	pos = 0;
	while (curr->next)
	{
		next = curr->next;
		if (curr->index < index && index < next->index)
			return (pos + 1);
		if (curr->index > next->index)
		{
			if (index > curr->index || index < next->index)
				return (pos + 1);
		}
		curr = curr->next;
		pos++;
	}
	return (0);
}

void	set_dirs(t_move *curr, t_ps *wrapper)
{
	curr->dir_a = 0;
	curr->dir_b = 0;
	if (curr->pos_a > wrapper->a.size - curr->pos_a)
		curr->dir_a = 1;
	if (curr->pos_b > wrapper->b.size - curr->pos_b)
		curr->dir_b = 1;
}

int	get_move_cost(t_move move, t_ps *wrapper)
{
	int	cost_a;
	int	cost_b;

	cost_a = get_cost(move.pos_a, wrapper->a.size);
	cost_b = get_cost(move.pos_b, wrapper->b.size);
	if (move.dir_a == move.dir_b)
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

int	get_pos(t_stack stack, t_node *target)
{
	t_node	*temp;
	int		counter;

	counter = 0;
	temp = stack.head;
	while (temp != target)
	{
		temp = temp->next;
		counter++;
	}
	return (counter);
}
