/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:05:06 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/22 13:36:49 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_init_map(t_list *node, void *(*f)(void *),
	void (*del)(void *))
{
	void	*newcontent;
	t_list	*newnode;

	if (node == NULL)
		return (NULL);
	newcontent = f(node->content);
	newnode = ft_lstnew(newcontent);
	if (newcontent == NULL || newnode == NULL)
	{
		if (del)
			del(newcontent);
		free(newnode);
		return (NULL);
	}
	return (newnode);
}

static t_list	*ft_node_map(t_list *node, void *(*f)(void *),
	void (*del)(void *), t_list *cpy)
{
	void	*newcontent;
	t_list	*newnode;

	newcontent = f(node->content);
	newnode = ft_lstnew(newcontent);
	if (newcontent == NULL || newnode == NULL)
	{
		if (del)
			del(newcontent);
		free(newnode);
		return (NULL);
	}
	cpy->next = newnode;
	return (newnode);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmp;

	newlst = ft_init_map(lst, f, del);
	if (newlst == NULL)
		return (NULL);
	lst = lst->next;
	tmp = newlst;
	while (lst)
	{
		tmp = ft_node_map(lst, f, del, tmp);
		if (tmp == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (newlst);
}
