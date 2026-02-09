/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonatanamir <yonatanamir@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:05:41 by yonatanamir       #+#    #+#             */
/*   Updated: 2026/02/05 14:22:56 by yonatanamir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_ps
{
	t_stack			a;
	t_stack			b;
}					t_ps;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				size;

}					t_stack;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;

}					t_node;

#endif
