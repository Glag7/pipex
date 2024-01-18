/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr_to_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:19:38 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/19 21:46:23 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_addtstr(t_list **lst, t_list *tmp, t_str *tstr)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (tstr == NULL || tstr->s == NULL || node == NULL)
	{
		if (tstr)
			free(tstr->s);
		free(tstr);
		free(node);
		return (NULL);
	}
	node->next = NULL;
	node->content = tstr;
	if (*lst == NULL)
		*lst = node;
	else
		tmp->next = node;
	return (node);
}

t_list	*ft_tstr_to_lst(t_str tstr, char *charset)
{
	size_t	i;
	size_t	off;
	t_list	*lst;
	t_list	*tmp;
	t_str	*tmptstr;

	lst = NULL;
	i = 0;
	off = 0;
	while (i < tstr.len || i == 0)
	{
		while (i + 1 < tstr.len && ft_in(tstr.s[i], charset) == -1)
			i++;
		tmptstr = malloc(sizeof(t_str));
		if (tmptstr)
			*tmptstr = ft_tstr_dupstr(tstr.s + off, i - off + !!tstr.len);
		tmp = ft_addtstr(&lst, tmp, tmptstr);
		if (tmp == NULL)
		{
			ft_lstclear(&lst, &ft_tstrfree);
			return (NULL);
		}
		off = i++ + 1;
	}
	return (lst);
}
