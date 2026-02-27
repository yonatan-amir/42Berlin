/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 19:41:56 by yoyo              #+#    #+#             */
/*   Updated: 2026/02/27 19:42:18 by yoyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static t_node	*node_struct(int value, int index)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL;
	return (node);
}

static int	first_node(t_stack *stack, int *i, int argc, char **argv)
{
	t_node	*node;
	int		num;

	num = atoi(argv[*i]);
	if (!num)
		return (0);
	node = node_struct(num, i);
	if (node == 0)
		return (0);
	stack->head = node;
	stack->tail = node;
	stack->tail->next = node;
	stack->size += 1;
	(*i)++;
	return (1);
}
