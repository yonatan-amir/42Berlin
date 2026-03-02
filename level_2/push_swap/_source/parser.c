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

static int	*merge_nums(int *base, int base_count, int *chunk, int chunk_count)
{
	int	*merged;
	int	i;

	if (!chunk || chunk_count <= 0)
		return (NULL);
	merged = malloc(sizeof(int) * (base_count + chunk_count));
	if (!merged)
		return (NULL);
	i = 0;
	while (i < base_count)
	{
		merged[i] = base[i];
		i++;
	}
	while (i < base_count + chunk_count)
	{
		merged[i] = chunk[i - base_count];
		i++;
	}
	return (merged);
}

int	parser(int **nums, int *count, int argc, char **argv)
{
	int	i;
	int	chunk_count;
	int	*chunk;
	int	*merged;

	if (!nums || !count || !argv || argc < 1)
		return (1);
	*nums = NULL;
	*count = 0;
	i = 1;
	while (i < argc)
	{
		chunk_count = 0;
		chunk = num_converter(argv[i], &chunk_count);
		if (!chunk)
			return (free(*nums), *nums = NULL, *count = 0, 1);
		merged = merge_nums(*nums, *count, chunk, chunk_count);
		free(chunk);
		if (!merged)
			return (free(*nums), *nums = NULL, *count = 0, 1);
		free(*nums);
		*nums = merged;
		*count += chunk_count;
		i++;
	}
	if (check_dup(*nums, *count) != 0)
		return (free(*nums), *nums = NULL, 1);
	return (0);
}
