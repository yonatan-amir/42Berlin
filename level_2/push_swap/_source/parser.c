#include "push_swap.h"

char	**create_arr_from_nums(int *status, const char *nptr)
{
	int		i;
	char	**arr;

	if (!nptr || !status)
	{
		*status = -1;
		return (NULL);
	}
	i = 0;
	while (nptr[i] && nptr[i] != ' ')
		i++;
	if (!nptr[i])
	{
		*status = 0;
		return (NULL);
	}
	arr = ft_split(nptr, ' ');
	if (!arr || !arr[0])
	{
		free_tokens(arr);
		*status = -1;
		return (NULL);
	}
	*status = 1;
	return (arr);
}

int	parser(int *status, int **nums, int *count, int argc, char **argv)
{
	int	i;

	i = 0;
	if (!nums || !count || !argv)
		return (1);
	if (argc < 2)
		return (*nums = NULL, *count = 0, 0);
	nums = create_arr_from_nums(&status, argv);
	if (status - 1)
		return (*nums = NULL, *count = 0, 0);
	*nums = NULL;
	*count = 0;
	return (0);
}
