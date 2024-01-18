/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:16:18 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/02 14:55:09 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	size_t			i;

	c1 = *s1;
	c2 = *s2;
	i = 0;
	while (i < n && c1 && c1 == c2)
	{
		c1 = s1[i];
		c2 = s2[i];
		i++;
	}
	if (n)
		return (c1 - c2);
	return (0);
}
