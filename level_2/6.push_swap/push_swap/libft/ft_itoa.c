/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:16:39 by yamir             #+#    #+#             */
/*   Updated: 2025/12/01 20:04:52 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static char	*fill_digits(char *s, long nb, int len, int isneg)
{
	while (len--)
	{
		s[len + isneg] = (nb % 10) + '0';
		nb /= 10;
	}
	if (isneg)
		s[0] = '-';
	return (s);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	int		isneg;
	char	*s;
	long	temp;

	nb = n;
	isneg = (n < 0);
	if (isneg)
		nb = -nb;
	len = (nb == 0);
	temp = nb;
	while (temp && ++len)
		temp /= 10;
	s = malloc(len + isneg + 1);
	if (!s)
		return (NULL);
	s[len + isneg] = '\0';
	fill_digits(s, nb, len, isneg);
	return (s);
}
