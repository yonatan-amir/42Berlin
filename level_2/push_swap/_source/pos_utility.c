/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:10:11 by yoyo              #+#    #+#             */
/*   Updated: 2026/03/16 19:10:39 by yoyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target_pos(t_stack stack_a, int index)
{
	t_node	*temp;
	int		counter;

	counter = 0;
	temp = stack_a.head;
	while (temp->next && temp->next->index < index)
	{
		temp = temp->next;
		counter++;
	}
	return (counter + 1);
}

int	get_pos(t_stack stack, t_node *target)
{
	t_node *temp;
	int counter;

	counter = 0;
	temp = stack.head;
	while (temp != target)
	{
		temp = temp->next;
		counter++;
	}
	return (counter);
}