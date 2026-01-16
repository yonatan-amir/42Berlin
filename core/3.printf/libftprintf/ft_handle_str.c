/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathanamir <jonathanamir@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:54:32 by jonathanami       #+#    #+#             */
/*   Updated: 2026/01/16 21:21:45 by jonathanami      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_str(int *i, va_list *args)
{
	const char	*s;
	int			counter;

	s = va_arg(*args, const char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		(*i)++;
		return (6);
	}
	counter = 0;
	while (*s)
	{
		write(1, s, 1);
		s++;
		counter++;
	}
	(*i)++;
	return (counter);
}
