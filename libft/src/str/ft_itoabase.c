/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:54:43 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/23 17:23:31 by glaguyon         ###   ########.fr       */
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

char	*ft_itoabase(ssize_t n, const char *base)
{
	size_t	numlen;
	size_t	len;
	size_t	num;
	char	*arg;
	char	tmp[66];

	len = ft_strlen(base);
	if (n < 0)
		num = -n;
	else
		num = n;
	*tmp = '\0';
	numlen = 1;
	while (num || numlen == 1)
	{
		tmp[numlen] = base[num % len];
		num /= len;
		numlen++;
	}
	arg = malloc((numlen + (n < 0)) * sizeof(char));
	ft_fill_arg(arg, tmp + numlen + (n < 0) - 1, n < 0);
	return (arg);
}
