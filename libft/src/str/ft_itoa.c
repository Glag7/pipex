/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:24:20 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/23 17:13:07 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill_arg(char *arg, char *tmp, short neg)
{
	size_t	i;
	char	c;

	if (arg == NULL)
		return ;
	i = 0;
	if (neg)
	{
		i++;
		arg[0] = '-';
	}
	c = *(tmp - i);
	while (c)
	{
		arg[i] = c;
		i++;
		c = *(tmp - i);
	}
	arg[i] = '\0';
}

char	*ft_itoa(ssize_t n)
{
	size_t	numlen;
	size_t	num;
	char	*arg;
	char	tmp[21];
	short	neg;

	neg = 0;
	num = n;
	if (n < 0)
	{
		neg = 1;
		num = -n;
	}
	*tmp = '\0';
	numlen = 1;
	while (num || numlen == 1)
	{
		tmp[numlen] = num % 10 + '0';
		num /= 10;
		numlen++;
	}
	arg = malloc((numlen + neg) * sizeof(char));
	ft_fill_arg(arg, tmp + numlen + neg - 1, neg);
	return (arg);
}
