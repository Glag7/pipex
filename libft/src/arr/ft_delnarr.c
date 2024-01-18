/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delnarr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:00:06 by glaguyon          #+#    #+#             */
/*   Updated: 2024/01/14 18:58:45 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delnarr(void *restrict arr, void (del)(void *restrict), size_t n)
{
	size_t				i;
	void	*restrict	tmp;
	void	**restrict	ptr;

	i = 0;
	ptr = arr;
	tmp = ptr[i];
	while (i < n)
	{
		del(tmp);
		i++;
		tmp = ptr[i];
	}
	free(ptr);
}
