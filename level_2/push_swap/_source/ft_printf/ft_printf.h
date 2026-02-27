/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathanamir <jonathanamir@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:32:26 by yamir             #+#    #+#             */
/*   Updated: 2026/01/19 17:48:32 by jonathanami      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		sharp;
	int		plus;
	int		space;
	int		width;
	int		precision;
	int		precision_set;
	char	spec;

}			t_flags;

int			ft_printf(const char *s, ...);
int			ft_handle_percent(int *i);
int			ft_handle_char(int *i, va_list *args);
int			ft_handle_str(int *i, va_list *args);
int			ft_handle_int(int *i, va_list *args);
int			ft_handle_ptr(int *i, va_list *args);
int			ft_handle_u(int *i, va_list *args);
int			ft_handle_x(int *i, va_list *args, const char *lookup);
void		flag_brain(const char *s, int *i, t_flags *f);

#endif
