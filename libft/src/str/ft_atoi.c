/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:31:30 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/22 17:34:18 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	ft_atoi_unsigned(const char *nptr)
{
	char	c;
	size_t	num;

	num = 0;
	c = *nptr;
	while (c >= '0' && c <= '9')
	{
		num = num * 10 + c - '0';
		nptr++;
		c = *nptr;
	}
	return (num);
}

ssize_t	ft_atoi(const char *nptr)
{
	size_t	num;
	short	neg;
	char	c;

	c = *nptr;
	neg = 0;
	while (c == ' ' || (c >= 9 && c <= 13))
	{
		nptr++;
		c = *nptr;
	}
	if (c == '+')
		nptr++;
	else if (c == '-')
	{
		neg = 1;
		nptr++;
	}
	num = ft_atoi_unsigned(nptr);
	if (neg)
		return (-num);
	return (num);
}
