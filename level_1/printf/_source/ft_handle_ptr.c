/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathanamir <jonathanamir@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:10:23 by jonathanami       #+#    #+#             */
/*   Updated: 2026/01/16 21:22:51 by jonathanami      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_ul(unsigned long v)
{
	char		buf[32];
	int			idx;
	int			count;
	const char	*lookup;

	lookup = "0123456789abcdef";
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

int	ft_handle_ptr(int *i, va_list *args)
{
	void			*p;
	unsigned long	v;
	int				count;

	p = va_arg(*args, void *);
	if (p == NULL)
	{
		write(1, "(nil)", 5);
		(*i)++;
		return (5);
	}
	write(1, "0x", 2);
	count = 2;
	v = (unsigned long)p;
	count += print_hex_ul(v);
	(*i)++;
	return (count);
}
