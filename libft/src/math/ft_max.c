/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:28:28 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/29 16:57:22 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline ssize_t	ft_max(ssize_t a, ssize_t b)
{
	if (a > b)
		return (a);
	return (b);
}