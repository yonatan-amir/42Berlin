#include "ft_printf/libft/libft.h"
#include "limits.h"
#include "push_swap.h"

void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		tokens[i] = NULL;
		i++;
	}
	free(tokens);
}

int	ft_atoi_swap(const char *nptr, int *out)
{
	long	num;
	int		sign;
	int		i;

	if (!nptr || !out)
		return (0);
	num = 0;
	sign = 1;
	i = 0;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	if (!ft_isdigit(nptr[i]))
		return (0);
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			return (0);
		num = num * 10 + (nptr[i] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && -num < INT_MIN))
			return (0);
		i++;
	}
	*out = (int)(num * sign);
	return (1);
}

char	**check_spaces(int *status, const char *nptr)
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

static int	*tokens_to_nums(char **tokens, int *out_count)
{
	int	count;
	int	i;
	int	nbr;
	int	*nums;

	if (!tokens || !out_count)
		return (*out_count = 0, NULL);
	count = 0;
	while (tokens[count])
		count++;
	nums = malloc(sizeof(int) * count);
	if (!nums)
		return (free_tokens(tokens), *out_count = 0, NULL);
	i = 0;
	while (i < count)
	{
		if (!ft_atoi_swap(tokens[i], &nbr))
			return (free(nums), free_tokens(tokens), *out_count = 0, NULL);
		nums[i++] = nbr;
	}
	free_tokens(tokens);
	*out_count = count;
	return (nums);
}

int	*num_converter(const char *nptr, int *out_count)
{
	int status;
	int nbr;
	char **tokens;
	int *nums;

	if (!out_count || !nptr)
		return (NULL);
	status = 0;
	tokens = check_spaces(&status, nptr);
	if (status == -1)
		return (*out_count = 0, NULL);
	if (status == 0)
	{
		if (!ft_atoi_swap(nptr, &nbr))
			return (*out_count = 0, NULL);
		nums = malloc(sizeof(int));
		if (!nums)
			return (free_tokens(tokens), *out_count = 0, NULL);
		nums[0] = nbr;
		*out_count = 1;
		return (nums);
	}
	return (tokens_to_nums(tokens, out_count));
}