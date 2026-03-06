/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:02:44 by yoyo              #+#    #+#             */
/*   Updated: 2026/03/06 13:02:45 by yoyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_program(t_ps *wrapper)
{
	if (!wrapper)
		return (1);
	wrapper->a.head = NULL;
	wrapper->a.tail = NULL;
	wrapper->a.size = 0;
	wrapper->b.head = NULL;
	wrapper->b.tail = NULL;
	wrapper->b.size = 0;
	return (0);
}
