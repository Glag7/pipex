/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttstr_to_tstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:17:46 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/20 01:26:14 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str	ft_lsttstr_to_tstr(t_list **lst, size_t len, void (del)(void *),
	short (end)(t_str *))
{
	t_list	*ob;
	t_str	s;
	int		i;

	ob = *lst;
	s = (t_str){malloc((len + 1) * sizeof(char)), len};
	if (ob == NULL || s.s == NULL)
	{
		free(s.s);
		ft_lstclear(lst, del);
		return ((t_str){NULL, 0});
	}
	i = 0;
	while (ob->next && (!end || !end(ob->content)))
	{
		ft_memcpy(s.s + i, ((t_str *)ob->content)->s,
			((t_str *)ob->content)->len);
		i += ((t_str *)ob->content)->len;
		ft_lstpop(&ob, del, 1);
	}
	ft_memcpy(s.s + i, ((t_str *)ob->content)->s, ((t_str *)ob->content)->len);
	s.s[i + ((t_str *)ob->content)->len] = '\0';
	ft_lstpop(&ob, del, 1);
	*lst = ob;
	return (s);
}
