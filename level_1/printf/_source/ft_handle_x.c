/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathanamir <jonathanamir@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:40:34 by jonathanami       #+#    #+#             */
/*   Updated: 2026/01/16 22:03:17 by jonathanami      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_ul(unsigned int v, const char *lookup)
{
	char	buf[32];
	int		idx;
	int		count;

	idx = 0;
	while (v > 0)
	{
		buf[idx] = lookup[v % 16];
		v /= 16;
		idx++;
	}
	count = 0;
	while (idx > 0)
	{
		idx--;
		write(1, &buf[idx], 1);
		count++;
	}
	return (count);
}

int	ft_handle_x(int *i, va_list *args, const char *lookup)
{
	unsigned int	p;
	int				count;

	p = va_arg(*args, unsigned int);
	count = 0;
	if (p == 0)
	{
		write(1, "0", 1);
		(*i)++;
		return (count + 1);
	}
	count += print_hex_ul(p, lookup);
	(*i)++;
	return (count);
}
