/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:10:45 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/23 17:21:06 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_nbr(char *tmp, short neg, int fd)
{
	size_t	i;
	char	c;
	char	toprint[66];

	i = 0;
	if (neg)
	{
		i++;
		toprint[0] = '-';
	}
	c = *(tmp - i);
	while (c)
	{
		toprint[i] = c;
		i++;
		c = *(tmp - i);
	}
	write(fd, toprint, i);
}

void	ft_putnbrbase_fd(ssize_t n, int fd, char *base)
{
	size_t	numlen;
	size_t	len;
	size_t	num;
	char	tmp[66];
	short	neg;

	num = n;
	len = ft_strlen(base);
	if (n < 0)
	{
		neg = 1;
		num = -n;
	}
	else
		neg = 0;
	*tmp = '\0';
	numlen = 1;
	while (num || numlen == 1)
	{
		tmp[numlen] = base[num % len];
		num /= len;
		numlen++;
	}
	ft_print_nbr(tmp + numlen + neg - 1, neg, fd);
}
