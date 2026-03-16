/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:14:23 by yoyo              #+#    #+#             */
/*   Updated: 2026/03/16 19:48:53 by yoyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute(t_ps *wrapper, t_move move)
{
}

static void	set_dirs(t_move *curr, t_ps *wrapper)
{
	curr->dir_a = 0;
	curr->dir_b = 0;
	if (curr->pos_a > wrapper->a.size - curr->pos_a)
		curr->dir_a = 1;
	if (curr->pos_b > wrapper->b.size - curr->pos_b)
		curr->dir_b = 1;
}

static int	get_cost(int pos, int size)
{
	if (pos <= size - pos)
		return (pos);
	return (size - pos);
}

static t_move	find_cheapest(t_ps *wrapper)
{
	t_move	best;
	t_move	curr;
	t_node	*temp;

	temp = wrapper->b.head;
	curr.pos_b = get_pos(wrapper->b, temp);
	curr.pos_a = get_target_pos(wrapper->a, temp->index);
	set_dirs(&curr, wrapper);
	best = curr;
	temp = temp->next;
	while (temp)
	{
		curr.pos_a = get_target_pos(wrapper->a, temp->index);
		curr.pos_b = get_pos(wrapper->b, temp);
		set_dirs(&curr, wrapper);
		if (get_cost(curr.pos_a, wrapper->a.size) + get_cost(curr.pos_b,
				wrapper->b.size) < get_cost(best.pos_a, wrapper->a.size)
			+ get_cost(best.pos_b, wrapper->b.size))
			best = curr;
		temp = temp->next;
	}
	return (best);
}

int	insert_chunks(t_ps *wrapper)
{
	t_move	move;

	while (wrapper->b.size != 0)
	{
		move = find_cheapest(wrapper);
		execute(wrapper, move);
	}
	return (0);
}
