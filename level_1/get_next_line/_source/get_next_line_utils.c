/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathanamir <jonathanamir@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:07:34 by jonathanami       #+#    #+#             */
/*   Updated: 2026/01/28 11:58:54 by jonathanami      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*append(char *stash, char *buf)
{
	int		i;
	int		j;
	int		k;
	char	*s;

	if (!stash && !buf)
		return (NULL);
	i = 0;
	while (stash && stash[i])
		i++;
	j = 0;
	while (buf && buf[j])
		j++;
	s = malloc(i + j + 1);
	if (!s)
		return (NULL);
	k = i;
	while (k--)
		s[k] = stash[k];
	k = j;
	while (k--)
		s[i + k] = buf[k];
	s[i + j] = '\0';
	return (s);
}

static char	*duplicate(char *s, int len)
{
	int		n;
	int		i;
	char	*out;

	if (!s)
		return (NULL);
	n = 0;
	if (len < 0)
		while (s[n])
			n++;
	else
		n = len;
	out = malloc(n + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (i < n)
	{
		out[i] = s[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

static char	*free_all(char **stash, char *line, char *old)
{
	if (line)
		free(line);
	free(old);
	*stash = NULL;
	return (NULL);
}

int	has_n(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*split(char **stash)
{
	int		i;
	char	*old;
	char	*line;

	if (!stash || !*stash)
		return (NULL);
	old = *stash;
	i = 0;
	while (old[i] && old[i] != '\n')
		i++;
	if (old[i] == '\n')
		i++;
	line = duplicate(old, i);
	if (!line)
		return (free_all(stash, NULL, old));
	*stash = NULL;
	if (old[i])
	{
		*stash = duplicate(old + i, -1);
		if (!*stash)
			return (free_all(stash, line, old));
	}
	free(old);
	return (line);
}
