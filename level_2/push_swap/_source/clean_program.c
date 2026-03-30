/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 13:08:47 by yamir             #+#    #+#             */
/*   Updated: 2026/03/30 13:08:47 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	free_stack(t_node *current)
{
	t_node	*temp;

	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}

void	clean_program(t_ps *wrapper)
{
	free_stack(wrapper->a.head);
	free_stack(wrapper->b.head);
}
