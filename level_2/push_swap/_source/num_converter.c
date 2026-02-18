/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:55:12 by yonatanamir       #+#    #+#             */
/*   Updated: 2026/02/18 19:30:18 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

int	*num_converter(const char *nptr, int *out_count)
{
	int		status;
	int		nbr;
	char	**tokens;
	int		*nums;
	int		temp;
	int		i;

	status = 0;
	tokens = check_spaces(&status, nptr);
	if (status == -1)
		return (*out_count = 0, NULL);
	else if (status == 0)
	{
		temp = ft_atoi_swap(nptr, &nbr);
		if (!temp)
			return (*out_count = 0, NULL);
		nums = malloc(sizeof(int));
		if (!nums)
			return (NULL);
		nums[0] = nbr;
		return (*out_count = 1, nums);
	}
	else
	{
		*out_count = 0;
		while (tokens[*out_count])
			*out_count++;
		nums = malloc(sizeof(int) * *out_count);
		if (!nums)
			return (free(tokens), *out_count = 0, NULL);
	}
	i = 0;
	while (i < *out_count - 1)
	{
		if (!ft_atoi_swap(tokens[i], &nbr))
			return (free(tokens), *out_count = 0, NULL);
		nums[i] = nbr;
		i++;
	}
	free(tokens);
	return (nums);
}

int	ft_atoi_swap(const char *nptr, int *out)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (!nptr[i])
		return (0);
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
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

	if (!nptr)
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
		*status = -1;
		return (NULL);
	}
	*status = 1;
	return (arr);
}
