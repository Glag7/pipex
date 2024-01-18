/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:05:03 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/16 16:57:36 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str_1;
	unsigned char	*str_2;
	size_t			*long1;
	size_t			*long2;
	size_t			i;

	str_1 = (unsigned char *) s1;
	str_2 = (unsigned char *) s2;
	long1 = (size_t *) s1;
	long2 = (size_t *) s2;
	i = 0;
	while (i < n / sizeof(size_t))
	{
		if (long1[i] != long2[i])
			break ;
		i++;
	}
	i *= sizeof(size_t);
	while (i < n)
	{
		if (str_1[i] != str_2[i])
			return (str_1[i] - str_2[i]);
		i++;
	}
	return (0);
}
