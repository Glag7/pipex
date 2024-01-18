/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:59:37 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/29 21:03:48 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpop(t_list **lst, void (del)(void *), int n)
{
	int		i;
	t_list	*node;
	t_list	*next;

	i = 0;
	node = *lst;
	while (node && i < n)
	{
		next = node->next;
		if (del)
			del(node->content);
		free(node);
		node = next;
		i++;
	}
	*lst = node;
}
