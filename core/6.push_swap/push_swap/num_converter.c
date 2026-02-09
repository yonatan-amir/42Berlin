/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonatanamir <yonatanamir@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:55:12 by yonatanamir       #+#    #+#             */
/*   Updated: 2026/02/06 18:39:16 by yonatanamir      ###   ########.fr       */
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

	status = 0;
	tokens = check_spaces(&status, nptr);
	if (status == -1)
		return (*out_count = 0, NULL);
	else if (status == 0)
	{
		if (check_digit(nptr))
		{
			ft_atoi_swap(nptr, &nbr);
			nums = malloc(sizeof(int));
			if (!nums)
				return (NULL);
			nums[0] = nbr;
			return (*out_count = 1, nums);
		}
		return (NULL);
	}
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
