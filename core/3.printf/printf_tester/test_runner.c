/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_runner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathanamir <jonathanamir@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:27:44 by yamir             #+#    #+#             */
/*   Updated: 2026/01/12 12:26:40 by jonathanami      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"

t_test_case	g_test_cases[] = {
	{"literal", test_literal},
};

int	main(void)
{
	int	passed;
	int	total;
	int	i;

	i = 0;
	passed = 0;
	total = sizeof(g_test_cases) / sizeof(g_test_cases[0]);
	printf(YELLOW "------------------------------\n" RESET);
	while (i < total)
	{
		if (g_test_cases[i].run())
		{
			passed++;
		}
		i++;
	}
	printf(YELLOW "------------------------------\n" RESET);
	printf(YELLOW "\n%d/%d tests passed\n" RESET, passed, total);
	return (passed == total ? 0 : 1);
}
