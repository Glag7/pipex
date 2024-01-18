/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:02:38 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/21 19:19:54 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	memsize;
	size_t	i;
	size_t	*memlong;
	char	*mem;

	memsize = nmemb * size;
	memlong = malloc(memsize);
	mem = (char *) memlong;
	if (mem == NULL)
		return (mem);
	i = 0;
	while (i < memsize / sizeof(size_t))
	{
		memlong[i] = 0;
		i++;
	}
	i *= sizeof(size_t);
	while (i < memsize)
	{
		mem[i] = 0;
		i++;
	}
	return ((void *) mem);
}
