/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathanamir <jonathanamir@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:47:36 by jonathanami       #+#    #+#             */
/*   Updated: 2026/01/16 21:21:45 by jonathanami      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_percent(int *i)
{
	char	c;

	c = '%';
	write(1, &c, 1);
	(*i)++;
	return (1);
}
