/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathanamir <jonathanamir@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:32:26 by yamir             #+#    #+#             */
/*   Updated: 2026/01/16 22:04:08 by jonathanami      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_handle_percent(int *i);
int	ft_handle_char(int *i, va_list *args);
int	ft_handle_str(int *i, va_list *args);
int	ft_handle_int(int *i, va_list *args);
int	ft_handle_ptr(int *i, va_list *args);
int	ft_handle_u(int *i, va_list *args);
int	ft_handle_x(int *i, va_list *args, const char *lookup);

#endif
