/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:52:22 by yamir             #+#    #+#             */
/*   Updated: 2025/12/05 18:12:07 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*r;

	if (!lst || !del || !*lst)
		return ;
	p = *lst;
	while (p)
	{
		r = p->next;
		del(p->content);
		free(p);
		p = r;
	}
	*lst = NULL;
}
