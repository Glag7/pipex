/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:24:57 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/21 18:18:36 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_rmemcpy(void *dest, const void *src, size_t n)
{
	char	*src_c;
	char	*dest_c;
	size_t	*src_long;
	size_t	*dest_long;
	size_t	i;

	i = n;
	src_c = (char *) src;
	dest_c = (char *) dest;
	src_long = (size_t *) src;
	dest_long = (size_t *) dest;
	while (i % sizeof(size_t))
	{
		dest_c[i - 1] = src_c[i - 1];
		i--;
	}
	i /= sizeof(sizeof(size_t));
	while (i)
	{
		dest_long[i - 1] = src_long[i - 1];
		i--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!(src < dest && (size_t) dest - (size_t) src <= n))
		ft_memcpy(dest, src, n);
	else
		ft_rmemcpy(dest, src, n);
	return (dest);
}
