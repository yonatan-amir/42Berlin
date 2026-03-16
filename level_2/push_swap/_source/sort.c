/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:15:05 by yoyo              #+#    #+#             */
/*   Updated: 2026/03/16 20:42:28 by yoyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_small(t_ps *wrapper)
{
	int	first;
	int	second;
	int	third;

	if (wrapper->a.size == 2)
	{
		if (wrapper->a.head->index > wrapper->a.tail->index)
			return (sa(wrapper));
		return ;
	}
	first = wrapper->a.head->index;
	second = wrapper->a.head->next->index;
	third = wrapper->a.tail->index;
	if (first < second && second < third)
		return ;
	if (first > second && second < third && first < third)
		return (sa(wrapper));
	if (first > second && second > third)
		return (sa(wrapper), rra(wrapper));
	if (first > second && second < third && first > third)
		return (ra(wrapper));
	if (first < second && second > third && first < third)
		return (sa(wrapper), ra(wrapper));
	return (rra(wrapper));
}

static int	get_chunk_size(int size)
{
	if (size <= 10)
		return (2);
	if (size <= 50)
		return (7);
	if (size <= 100)
		return (15);
	return (35);
}

static void	push_chunks(t_ps *wrapper)
{
	int	chunk_size;
	int	pushed;

	chunk_size = get_chunk_size(wrapper->a.size);
	pushed = 0;
	while (wrapper->a.size > 3)
	{
		if (wrapper->a.head->index <= pushed)
		{
			pb(wrapper);
			rb(wrapper);
			pushed++;
		}
		else if (wrapper->a.head->index <= pushed + chunk_size)
		{
			pb(wrapper);
			pushed++;
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
	int		counter;
	t_node	*temp;

	counter = 0;
	if (wrapper->a.size < 2 || is_sorted(wrapper->a))
		return (0);
	if (wrapper->a.size <= 3)
		return (sort_small(wrapper), 0);
	push_chunks(wrapper);
	sort_small(wrapper);
	insert_chunks(wrapper);
	temp = wrapper->a.head;
	while (temp->index != 0)
	{
		temp = temp->next;
		counter++;
	}
	if (counter <= wrapper->a.size - counter)
		while (wrapper->a.head->index != 0)
			ra(wrapper);
	else
		while (wrapper->a.head->index != 0)
			rra(wrapper);
	return (0);
}
