/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:32:13 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/21 18:54:08 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	*ptr_long;
	size_t	i;
	size_t	i_long;

	i = 0;
	i_long = sizeof(size_t);
	ptr = (char *) s;
	ptr_long = (size_t *) s;
	while (i_long < n)
	{
		ptr_long[i] = 0;
		i++;
		i_long += sizeof(size_t);
	}
	i_long -= sizeof(size_t);
	while (i_long < n)
	{
		ptr[i_long] = 0;
		i_long++;
	}
}
