/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathanamir <jonathanamir@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:13:30 by jonathanami       #+#    #+#             */
/*   Updated: 2026/01/16 21:21:45 by jonathanami      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_char(int *i, va_list *args)
{
	int	c;

	c = va_arg(*args, int);
	write(1, &c, 1);
	(*i)++;
	return (1);
}
