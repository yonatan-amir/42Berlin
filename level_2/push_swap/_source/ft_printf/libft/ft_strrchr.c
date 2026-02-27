/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:32:26 by yamir             #+#    #+#             */
/*   Updated: 2025/11/27 13:52:44 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	cc;
	int				i;
	int				j;

	i = 0;
	j = -1;
	cc = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == cc)
			j = i;
		i++;
	}
	if (j != -1)
		return ((char *)(s + j));
	if (cc == '\0')
		return ((char *)(s + i));
	else
		return (NULL);
}
