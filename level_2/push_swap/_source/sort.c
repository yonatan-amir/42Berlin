/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:15:05 by yoyo              #+#    #+#             */
/*   Updated: 2026/03/16 15:16:58 by yoyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_small(t_ps *wrapper)
{
	if (wrapper->a.size == 2)
	{
		if (wrapper->a.head->index > wrapper->a.tail->index)
			return (sa(wrapper));
		return ;
	}
	if (wrapper->a.head->index == 0 && wrapper->a.head->next->index == 2)
		return (rra(wrapper), sa(wrapper));
	else if (wrapper->a.head->index == 1 && wrapper->a.head->next->index == 0)
		return (sa(wrapper));
	else if (wrapper->a.head->index == 1 && wrapper->a.head->next->index == 2)
		return (rra(wrapper));
	else if (wrapper->a.head->index == 2 && wrapper->a.head->next->index == 0)
		return (ra(wrapper));
	else if (wrapper->a.head->index == 2 && wrapper->a.head->next->index == 1)
		return (sa(wrapper), rra(wrapper));
}

static int	get_chunk_size(int size)
{
	int	chunk_size;

	if (size <= 10)
		chunk_size = 2;
	else if (size <= 50)
		chunk_size = 4;
	else
		chunk_size = size / 10;
	chunk_size = size / chunk_size;
	return (chunk_size);
}

static void	push_chunks(t_ps *wrapper)
{
	int	chunk_size;
	int	curr_chunk;
	int	chunk_counter;

	chunk_size = get_chunk_size(wrapper->a.size);
	curr_chunk = chunk_size + 3;
	chunk_counter = chunk_size;
	while (wrapper->a.size > 3)
	{
		if (wrapper->a.head->index >= curr_chunk - chunk_size
			&& wrapper->a.head->index <= curr_chunk)
		{
			pb(wrapper);
			chunk_counter--;
			if (chunk_counter == 0)
			{
				curr_chunk += chunk_size;
				chunk_counter = chunk_size;
			}
		}
		else
			ra(wrapper);
	}
}

static int	is_sorted(t_stack stack_a)
{
	int		i;
	t_node	*temp_a;

	i = 0;
	temp_a = stack_a.head;
	while (i == temp_a->index)
	{
		if (!temp_a->next)
			break ;
		i++;
		temp_a = temp_a->next;
	}
	if (i == temp_a->index && !temp_a->next)
		return (1);
	return (0);
}

int	sort(t_ps *wrapper)
{
	if (wrapper->a.size < 2)
		return (0);
	if (is_sorted(wrapper->a))
		return (0);
	if (wrapper->a.size <= 3)
		return (sort_small(wrapper), 0);
	else
	{
		push_chunks(wrapper);
		sort_small(wrapper);
		insert_chunks(wrapper);
	}
	return (0);
}
