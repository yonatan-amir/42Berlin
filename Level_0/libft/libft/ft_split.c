/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathanamir <jonathanamir@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:05:10 by yamir             #+#    #+#             */
/*   Updated: 2025/12/11 13:06:22 by jonathanami      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **arr, unsigned int d)
{
	while (d > 0)
	{
		d--;
		free(arr[d]);
	}
	free(arr);
}

static unsigned int	word_count(char const *s, char c)
{
	unsigned int	i;
	unsigned int	d;

	i = 0;
	d = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			d++;
		i++;
	}
	return (d);
}

static char	**fill_array(char const *s, char c, char **arr)
{
	unsigned int	i;
	unsigned int	d;
	unsigned int	start;

	i = 0;
	d = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			arr[d] = ft_substr(s, start, i - start);
			if (!arr[d])
				return (free_all(arr, d), NULL);
			d++;
		}
		else
			i++;
	}
	arr[d] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = word_count(s, c);
	arr = (char **)malloc((i + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (fill_array(s, c, arr));
}
