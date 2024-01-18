/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swaplen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:53:32 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/28 16:36:57 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void	ft_swaplen(void *a, void *b, size_t len)
{
	void	*tmp;

	tmp = malloc(len);
	if (tmp == NULL)
		return ;
	ft_memcpy(tmp, a, len);
	ft_memcpy(a, b, len);
	ft_memcpy(b, tmp, len);
	free(tmp);
}
