/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:44:46 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/28 16:05:54 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freearr(void *restrict arr)
{
	size_t				i;
	void	*restrict	tmp;
	void	**restrict	ptr;

	i = 0;
	ptr = arr;
	tmp = ptr[i];
	while (tmp)
	{
		free(tmp);
		i++;
		tmp = ptr[i];
	}
	free(ptr);
}
