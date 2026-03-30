/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 13:09:48 by yamir             #+#    #+#             */
/*   Updated: 2026/03/30 13:09:49 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	check_dup(int *nums, int count)
{
	int	i;
	int	j;

	if (!nums)
		return (1);
	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (nums[i] == nums[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	*merge_nums(int *nums, int count, int *chunk, int chunk_count)
{
	int	*merged;
	int	i;

	if (!chunk || chunk_count <= 0)
		return (NULL);
	merged = malloc(sizeof(int) * (count + chunk_count));
	if (!merged)
		return (NULL);
	i = 0;
	while (i < count)
	{
		merged[i] = nums[i];
		i++;
	}
	while (i < count + chunk_count)
	{
		merged[i] = chunk[i - count];
		i++;
	}
	return (merged);
}

static int	append_converted(int **nums, int *count, const char *arg)
{
	int	*chunk;
	int	*merged;
	int	chunk_count;

	chunk_count = 0;
	chunk = num_converter(arg, &chunk_count);
	if (!chunk)
		return (free(*nums), *nums = NULL, *count = 0, 1);
	merged = merge_nums(*nums, *count, chunk, chunk_count);
	free(chunk);
	if (!merged)
		return (free(*nums), *nums = NULL, *count = 0, 1);
	free(*nums);
	*nums = merged;
	*count += chunk_count;
	return (0);
}

int	parser(int **nums, int *count, int argc, char **argv)
{
	int	i;

	if (!nums || !count || !argv || argc < 1)
		return (1);
	*nums = NULL;
	*count = 0;
	i = 1;
	while (i < argc)
	{
		if (append_converted(nums, count, argv[i]) != 0)
			return (1);
		i++;
	}
	if (check_dup(*nums, *count) != 0)
		return (free(*nums), *nums = NULL, 1);
	return (0);
}
