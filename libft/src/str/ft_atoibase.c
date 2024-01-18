/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:17:06 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/22 18:07:30 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	ft_atoibase_unsigned(const char *nptr, const char *base)
{
	ssize_t	c;
	size_t	num;
	size_t	len;

	num = 0;
	c = ft_in(*nptr, base);
	len = ft_strlen(base);
	while (c != -1)
	{
		num = num * len + c;
		nptr++;
		c = ft_in(*nptr, base);
	}
	return (num);
}

ssize_t	ft_atoibase(const char *nptr, const char *base)
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
	num = ft_atoibase_unsigned(nptr, base);
	if (neg)
		return (-num);
	return (num);
}
