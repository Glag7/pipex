/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:38:09 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/10 16:42:53 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzchar(void *s, size_t n)
{
	char	*ptr;
	size_t	*ptr_long;
	size_t	i;
	size_t	i_long;
	size_t	zeroes;

	i = 0;
	zeroes = 3472328296227680304;
	i_long = sizeof(size_t);
	ptr = (char *) s;
	ptr_long = (size_t *) s;
	while (i_long < n)
	{
		ptr_long[i] = zeroes;
		i++;
		i_long += sizeof(size_t);
	}
	i_long -= sizeof(size_t);
	while (i_long < n)
	{
		ptr[i_long] = '0';
		i_long++;
	}
}
