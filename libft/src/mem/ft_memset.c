/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:57:23 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/16 17:30:50 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			*ptr_long;
	size_t			cons;
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	c = (unsigned char) c;
	cons = c + (size_t)(c << 8) + (size_t)(c << 16) + ((size_t)c << 24)
		+ ((size_t)c << 32) + ((size_t)c << 40) + ((size_t)c << 48)
		+ ((size_t)c << 56);
	ptr = (unsigned char *) s;
	ptr_long = (size_t *) s;
	while (i < n / sizeof(size_t))
	{
		ptr_long[i] = cons;
		i++;
	}
	i *= sizeof(size_t);
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}
