/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathanamir <jonathanamir@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:36:09 by jonathanami       #+#    #+#             */
/*   Updated: 2026/01/28 11:59:44 by jonathanami      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	clear(char **stash)
{
	free(*stash);
	*stash = NULL;
}

static char	*flush(char **stash)
{
	char	*ret;

	ret = *stash;
	*stash = NULL;
	return (ret);
}

static int	has_content(char *s)
{
	if (s && *s)
		return (1);
	return (0);
}

static int	read_append(int fd, char **stash)
{
	ssize_t	res;
	char	buf[BUFFER_SIZE + 1];
	char	*old;

	res = read(fd, buf, BUFFER_SIZE);
	if (res < 0)
		return (-1);
	if (res == 0)
		return (0);
	buf[res] = '\0';
	old = *stash;
	*stash = append(*stash, buf);
	if (!*stash)
	{
		free(old);
		return (-1);
	}
	free(old);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	int			st;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (leftover && has_n(leftover))
		return (split(&leftover));
	while (1)
	{
		st = read_append(fd, &leftover);
		if (st == -1)
		{
			clear(&leftover);
			return (NULL);
		}
		if (leftover && has_n(leftover))
			return (split(&leftover));
		if (st == 0)
			break ;
	}
	if (has_content(leftover))
		return (flush(&leftover));
	return (NULL);
}
