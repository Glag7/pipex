/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:31:21 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/28 18:04:04 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	ft_part(char *restrict arr, size_t len, size_t memlen)
{
	size_t				i;
	size_t				j;
	char	*restrict	mid;

	i = 0;
	j = (len - 1) * memlen;
	mid = arr + ((len - 1) / 2) * memlen;
	while (i <= j)
	{
		while (ft_memcmp(arr + i, mid, memlen) < 0)
			i += memlen;
		while (ft_memcmp(arr + j, mid, memlen) > 0)
			j -= memlen;
		if (i <= j)
		{
			ft_swaplen(arr + i, arr + j, memlen);
			i += memlen;
			j -= memlen;
		}
	}
	return (j / memlen + 1);
}

static void	ft_sortlen_rec(char *restrict arr, size_t len, size_t memlen)
{
	size_t	tmp;

	if (len > 3)
	{
		tmp = ft_part(arr, len, memlen);
		ft_sortlen_rec(arr, tmp, memlen);
		ft_sortlen_rec(arr + tmp, len - tmp, memlen);
	}
	if (len == 3 && ft_memcmp(arr, arr + 2 * memlen, memlen) > 0)
		ft_swaplen(arr, arr + 2, memlen);
	if (len == 3 && ft_memcmp(arr + memlen, arr + 2 * memlen, memlen) > 0)
		ft_swaplen(arr + 1, arr + 2, memlen);
	if ((len == 2 || len == 3) && ft_memcmp(arr, arr + memlen, memlen) > 0)
		ft_swaplen(arr, arr + 1, memlen);
}

static inline size_t	ft_part_i(char *restrict arr, size_t len, size_t memlen)
{
	size_t				i;
	size_t				j;
	char	*restrict	mid;

	i = 0;
	j = (len - 1) * memlen;
	mid = arr + ((len - 1) / 2) * memlen;
	while (i <= j)
	{
		while (ft_memcmp(arr + i, mid, memlen) > 0)
			i += memlen;
		while (ft_memcmp(arr + j, mid, memlen) < 0)
			j -= memlen;
		if (i <= j)
		{
			ft_swaplen(arr + i, arr + j, memlen);
			i += memlen;
			j -= memlen;
		}
	}
	return (j / memlen + 1);
}

static void	ft_sortlen_rec_i(char *restrict arr, size_t len, size_t memlen)
{
	size_t	tmp;

	if (len > 3)
	{
		tmp = ft_part_i(arr, len, memlen);
		ft_sortlen_rec_i(arr, tmp, memlen);
		ft_sortlen_rec_i(arr + tmp, len - tmp, memlen);
	}
	if (len == 3 && ft_memcmp(arr, arr + 2 * memlen, memlen) < 0)
		ft_swaplen(arr, arr + 2, memlen);
	if (len == 3 && ft_memcmp(arr + memlen, arr + 2 * memlen, memlen) < 0)
		ft_swaplen(arr + 1, arr + 2, memlen);
	if ((len == 2 || len == 3) && ft_memcmp(arr, arr + memlen, memlen) < 0)
		ft_swaplen(arr, arr + 1, memlen);
}

void	ft_sortlen(void *restrict arr, size_t len, char rev, size_t memlen)
{
	if (!rev)
		ft_sortlen_rec((char *) arr, len, memlen);
	else
		ft_sortlen_rec_i((char *) arr, len, memlen);
}
