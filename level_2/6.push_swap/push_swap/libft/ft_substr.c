/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:34:41 by yamir             #+#    #+#             */
/*   Updated: 2025/12/05 14:46:24 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
	{
		p = malloc(1);
		if (!p)
			return (NULL);
		*p = '\0';
		return (p);
	}
	if (len > str_len - start)
		len = str_len - start;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, (s + start), len + 1);
	return (p);
}
