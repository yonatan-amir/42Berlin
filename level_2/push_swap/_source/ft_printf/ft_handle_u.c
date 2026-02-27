/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathanamir <jonathanamir@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:20:08 by jonathanami       #+#    #+#             */
/*   Updated: 2026/01/16 21:21:45 by jonathanami      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_u_nbr_fd(unsigned int n, int fd)
{
	char	c;

	if (n >= 10)
		ft_u_nbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

static int	ft_u_len(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_handle_u(int *i, va_list *args)
{
	unsigned int	n;
	int				counter;

	n = va_arg(*args, unsigned int);
	ft_u_nbr_fd(n, 1);
	counter = ft_u_len(n);
	(*i)++;
	return (counter);
}
