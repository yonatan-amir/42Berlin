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

static int	handle_case_basic(t_flags *f, int *i, int *char_printed,
		va_list *args)
{
	switch (f->spec)
	{
	case '%':
		ft_handle_percent(i) == 1 && (*char_printed += 1);
		return (1);
	case 'c':
		ft_handle_char(i, args) == 1 && (*char_printed += 1);
		return (1);
	case 's':
		*char_printed += ft_handle_str(i, args);
		return (1);
	default:
		return (0);
	}
}

static int	handle_case_num(t_flags *f, int *i, int *char_printed,
		va_list *args)
{
	switch (f->spec)
	{
	case 'd':
	case 'i':
		*char_printed += ft_handle_int(i, args);
		return (1);
	case 'p':
		*char_printed += ft_handle_ptr(i, args);
		return (1);
	case 'u':
		*char_printed += ft_handle_u(i, args);
		return (1);
	case 'x':
		*char_printed += ft_handle_x(i, args, "0123456789abcdef");
		return (1);
	case 'X':
		*char_printed += ft_handle_x(i, args, "0123456789ABCDEF");
		return (1);
	default:
		return (0);
	}
}

static int	handle_case(t_flags *f, int *i, int *char_printed, va_list *args)
{
	if (handle_case_basic(f, i, char_printed, args))
		return (1);
	if (handle_case_num(f, i, char_printed, args))
		return (1);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		char_printed;
	t_flags	flags;
	va_list	args;

	if (!s)
		return (0);
	i = 0;
	char_printed = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			flag_brain(s, &i, &flags);
			handle_case(&flags, &i, &char_printed, &args);
		}
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
