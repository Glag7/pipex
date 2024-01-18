/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:52:06 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/22 17:58:13 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_in(char c, const char *s)
{
	size_t	i;
	char	curr;

	i = 0;
	curr = *s;
	while (curr)
	{
		if (curr == c)
			return (i);
		i++;
		curr = s[i];
	}
	return (-1);
}
