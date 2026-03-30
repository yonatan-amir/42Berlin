/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 13:09:28 by yamir             #+#    #+#             */
/*   Updated: 2026/03/30 13:09:28 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"
#include "push_swap.h"
#include <stdlib.h>

static void	free_chars(char **chars)
{
	int	i;

	if (!chars)
		return ;
	i = 0;
	while (chars[i])
	{
		free(chars[i]);
		chars[i] = NULL;
		i++;
	}
	free(chars);
}

static int	ft_atoi_swap(const char *nptr, int *out)
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
	if (!ps_isdigit(nptr[i]))
		return (0);
	while (nptr[i])
	{
		if (!ps_isdigit(nptr[i]))
			return (0);
		num = num * 10 + (nptr[i] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && (-num) < INT_MIN))
			return (0);
		i++;
	}
	return (*out = (int)(num * sign), 1);
}

static char	**check_spaces(int *status, const char *nptr)
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
	arr = ps_split(nptr, ' ');
	if (!arr || !arr[0])
	{
		free_chars(arr);
		*status = -1;
		return (NULL);
	}
	*status = 1;
	return (arr);
}

static int	*chars_to_nums(char **chars, int *out_count)
{
	int	count;
	int	i;
	int	nbr;
	int	*nums;

	if (!chars || !out_count)
		return (*out_count = 0, NULL);
	count = 0;
	while (chars[count])
		count++;
	nums = malloc(sizeof(int) * count);
	if (!nums)
		return (free_chars(chars), *out_count = 0, NULL);
	i = 0;
	while (i < count)
	{
		if (!ft_atoi_swap(chars[i], &nbr))
			return (free(nums), free_chars(chars), *out_count = 0, NULL);
		nums[i++] = nbr;
	}
	free_chars(chars);
	*out_count = count;
	return (nums);
}

int	*num_converter(const char *nptr, int *out_count)
{
	int		status;
	int		nbr;
	char	**chars;
	int		*nums;

	if (!out_count || !nptr)
		return (NULL);
	status = 0;
	chars = check_spaces(&status, nptr);
	if (status == -1)
		return (*out_count = 0, NULL);
	if (status == 0)
	{
		if (!ft_atoi_swap(nptr, &nbr))
			return (*out_count = 0, NULL);
		nums = malloc(sizeof(int));
		if (!nums)
			return (free_chars(chars), *out_count = 0, NULL);
		nums[0] = nbr;
		*out_count = 1;
		return (nums);
	}
	return (chars_to_nums(chars, out_count));
}
