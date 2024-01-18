/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrarr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:27:49 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/28 15:49:51 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_chrarr_ptr(const void *restrict arr, const void *restrict tofind,
		size_t len, char (*cmp)(const void *restrict, const void *restrict))
{
	size_t					i;
	const void	**restrict	ptr = (const void **restrict) arr;

	i = 0;
	while (i < len)
	{
		if (cmp(ptr[i], tofind) == 0)
			return (i);
		i++;
	}
	return (-1);
}
