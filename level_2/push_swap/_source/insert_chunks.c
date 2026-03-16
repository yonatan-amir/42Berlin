/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:14:23 by yoyo              #+#    #+#             */
/*   Updated: 2026/03/16 20:51:09 by yoyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	apply_joint_rot(t_ps *wrapper, t_move move, int count, int steps[2])
{
	if (count < steps[0] && move.dir_a == 0
		&& count < steps[1] && move.dir_b == 0)
		return (rr(wrapper), 1);
	if (count < steps[0] && move.dir_a == 1
		&& count < steps[1] && move.dir_b == 1)
		return (rrr(wrapper), 1);
	return (0);
}

static void	apply_single_rot(t_ps *wrapper, t_move move,
		int count, int steps[2])
{
	if (count < steps[0] && move.dir_a == 0)
		ra(wrapper);
	if (count < steps[0] && move.dir_a == 1)
		rra(wrapper);
	if (count < steps[1] && move.dir_b == 0)
		rb(wrapper);
	if (count < steps[1] && move.dir_b == 1)
		rrb(wrapper);
}

static void	execute(t_ps *wrapper, t_move move)
{
	int	count;
	int	steps[2];

	count = 0;
	steps[0] = move.pos_a;
	steps[1] = move.pos_b;
	if (move.dir_a == 1)
		steps[0] = wrapper->a.size - move.pos_a;
	if (move.dir_b == 1)
		steps[1] = wrapper->b.size - move.pos_b;
	while (count < steps[0] || count < steps[1])
	{
		if (apply_joint_rot(wrapper, move, count, steps) == 0)
			apply_single_rot(wrapper, move, count, steps);
		count++;
	}
	pa(wrapper);
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
		if (get_move_cost(curr, wrapper) < get_move_cost(best, wrapper))
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
