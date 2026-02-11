/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathanamir <jonathanamir@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:39:19 by yamir             #+#    #+#             */
/*   Updated: 2026/01/19 17:56:20 by jonathanami      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_case(t_flags *f, int *i, int *char_printed, va_list *args)
{
	if (f->spec == '%')
		*char_printed += ft_handle_percent(i);
	else if (f->spec == 'c')
		*char_printed += ft_handle_char(i, args);
	else if (f->spec == 's')
		*char_printed += ft_handle_str(i, args);
	else if (f->spec == 'd' || f->spec == 'i')
		*char_printed += ft_handle_int(i, args);
	else if (f->spec == 'p')
		*char_printed += ft_handle_ptr(i, args);
	else if (f->spec == 'u')
		*char_printed += ft_handle_u(i, args);
	else if (f->spec == 'x')
		*char_printed += ft_handle_x(i, args, "0123456789abcdef");
	else if (f->spec == 'X')
		*char_printed += ft_handle_x(i, args, "0123456789ABCDEF");
	else
		return (0);
	return (1);
}

static void	handle_percent(const char *s, int *i, int *char_printed,
		va_list *args)
{
	t_flags	flags;

	(*i)++;
	flag_brain(s, i, &flags);
	handle_case(&flags, i, char_printed, args);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		char_printed;
	va_list	args;

	if (!s)
		return (0);
	i = 0;
	char_printed = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
			handle_percent(s, &i, &char_printed, &args);
		else
		{
			write(1, &s[i], 1);
			char_printed += 1;
			i++;
		}
	}
	va_end(args);
	return (char_printed);
}
