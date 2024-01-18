/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrarr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:24:25 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/28 15:32:04 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_chrarr_len(const void *restrict arr, const void *restrict tofind,
		size_t flen, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *) arr;
	len *= flen;
	while (i < len)
	{
		if (ft_memcmp(ptr + i, tofind, flen) == 0)
			return (i);
		i += flen;
	}
	return (-1);
}
