/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 19:41:42 by yoyo              #+#    #+#             */
/*   Updated: 2026/02/27 19:48:58 by yoyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	init_program(t_ps *wrapper, int argc, char **argv)
{
	int	count;
	int	*nums;
	int	status;

	(void)wrapper;
	count = 0;
	nums = NULL;
	if (argc < 2)
		return (0);
	status = parser(&status, &nums, &count, argc, argv);
	if (status != 0)
		return (status);
	free(nums);
	return (0);
}
