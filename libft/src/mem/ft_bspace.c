/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bspace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:00:45 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/07 20:06:16 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bspace(void *s, size_t n)
{
	char	*ptr;
	size_t	*ptr_long;
	size_t	i;
	size_t	i_long;
	size_t	spaces;

	i = 0;
	spaces = 2314885530818453536;
	i_long = sizeof(size_t);
	ptr = (char *) s;
	ptr_long = (size_t *) s;
	while (i_long < n)
	{
		ptr_long[i] = spaces;
		i++;
		i_long += sizeof(size_t);
	}
	i_long -= sizeof(size_t);
	while (i_long < n)
	{
		ptr[i_long] = ' ';
		i_long++;
	}
}
