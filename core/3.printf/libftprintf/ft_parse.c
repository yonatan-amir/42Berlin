/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathanamir <jonathanamir@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:32:34 by jonathanami       #+#    #+#             */
/*   Updated: 2026/01/19 17:53:47 by jonathanami      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	parse_flags(const char *s, int *i, t_flags *f)
{
	while (s[*i] == '-' || s[*i] == '+' || s[*i] == '#' || s[*i] == '0'
		|| s[*i] == ' ')
	{
		switch (s[*i])
		{
		case '-':
			f->minus = 1;
			break ;
		case '+':
			f->plus = 1;
			break ;
		case '#':
			f->sharp = 1;
			break ;
		case '0':
			f->zero = 1;
			break ;
		case ' ':
			f->space = 1;
			break ;
		default:
			break ;
		}
		(*i)++;
	}
}

void	init_flags(t_flags *f)
{
	f->minus = 0;
	f->zero = 0;
	f->sharp = 0;
	f->plus = 0;
	f->space = 0;
	f->width = 0;
	f->precision = 0;
	f->precision_set = 0;
	f->spec = 0;
}

void	flag_brain(const char *s, int *i, t_flags *f)
{
	init_flags(f);
	parse_flags(s, i, f);
	while (ft_isdigit(s[*i]))
	{
		f->width = f->width * 10 + (s[*i] - '0');
		(*i)++;
	}
	if (s[*i] == '.')
	{
		f->precision_set = 1;
		f->precision = 0;
		(*i)++;
		while (ft_isdigit(s[*i]))
		{
			f->precision = f->precision * 10 + (s[*i] - '0');
			(*i)++;
		}
	}
	f->spec = s[*i];
}
