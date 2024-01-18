/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freenarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:53:27 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/28 16:16:18 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freenarr(void *restrict arr, size_t n)
{
	size_t				i;
	void	*restrict	tmp;
	void	**restrict	ptr;

	i = 0;
	ptr = arr;
	tmp = ptr[i];
	while (i < n)
	{
		free(tmp);
		i++;
		tmp = ptr[i];
	}
	free(ptr);
}
