/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrarr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:19:57 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/28 15:32:16 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_chrarr_int(const int *restrict arr, int tofind, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == tofind)
			return (i);
		i++;
	}
	return (-1);
}
