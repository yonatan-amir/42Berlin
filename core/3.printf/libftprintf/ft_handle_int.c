/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathanamir <jonathanamir@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:42:57 by jonathanami       #+#    #+#             */
/*   Updated: 2026/01/16 21:19:57 by jonathanami      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_handle_int(int *i, va_list *args)
{
	int		n;
	int		counter;
	long	temp;

	n = va_arg(*args, int);
	ft_putnbr_fd(n, 1);
	temp = n;
	counter = 0;
	if (temp < 0)
	{
		counter++;
		temp = -temp;
	}
	if (temp == 0)
		counter = 1;
	while (temp > 0)
	{
		temp /= 10;
		counter++;
	}
	(*i)++;
	return (counter);
}
