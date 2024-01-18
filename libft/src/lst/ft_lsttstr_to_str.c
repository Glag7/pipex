/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttstr_to_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:17:46 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/20 01:28:49 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lsttstr_to_str(t_list **lst, size_t len, void (del)(void *),
	short (end)(t_str *))
{
	t_list	*obj;
	char	*s;
	int		i;

	obj = *lst;
	s = malloc((len + 1) * sizeof(char));
	if (obj == NULL || s == NULL)
	{
		free(s);
		ft_lstclear(lst, del);
		return (NULL);
	}
	i = 0;
	while (obj->next && (!end || !end(obj->content)))
	{
		ft_memcpy(s + i, ((t_str *)obj->content)->s,
			((t_str *)obj->content)->len);
		i += ((t_str *)obj->content)->len;
		ft_lstpop(&obj, del, 1);
	}
	ft_memcpy(s + i, ((t_str *)obj->content)->s, ((t_str *)obj->content)->len);
	s[i + ((t_str *)obj->content)->len] = '\0';
	ft_lstpop(&obj, del, 1);
	*lst = obj;
	return (s);
}
