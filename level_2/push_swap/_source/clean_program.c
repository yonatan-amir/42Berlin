/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 19:41:27 by yoyo              #+#    #+#             */
/*   Updated: 2026/03/06 14:19:12 by yoyo             ###   ########.fr       */
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
