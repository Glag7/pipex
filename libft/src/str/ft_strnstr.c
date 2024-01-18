/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:23:35 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/05 19:05:53 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short	ft_strhere(const char *big, const char *little, size_t len)
{
	char	cbig;
	char	clittle;
	size_t	i;

	cbig = *big;
	clittle = *little;
	i = 0;
	while (i < len && cbig && cbig == clittle)
	{
		i++;
		cbig = big[i];
		clittle = little[i];
	}
	if (clittle == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && big[i])
	{
		if (ft_strhere(big + i, little, len - i))
			return ((char *) big + i);
		i++;
	}
	if (*little == '\0')
		return ((char *) big + i);
	return ((char *) 0);
}
