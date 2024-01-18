/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:31:21 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/28 17:55:41 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	ft_part(long *restrict arr, size_t len)
{
	size_t	i;
	size_t	j;
	long	mid;

	i = 0;
	j = len - 1;
	mid = arr[(len - 1) / 2];
	while (i <= j)
	{
		while (arr[i] < mid)
			i++;
		while (arr[j] > mid)
			j--;
		if (i <= j)
		{
			ft_swaplong(arr + i, arr + j);
			i++;
			j--;
		}
	}
	return (j + 1);
}

static void	ft_sortlong_rec(long *restrict arr, size_t len)
{
	size_t	tmp;

	if (len > 3)
	{
		tmp = ft_part(arr, len);
		ft_sortlong_rec(arr, tmp);
		ft_sortlong_rec(arr + tmp, len - tmp);
	}
	if (len == 3 && arr[0] > arr[2])
		ft_swaplong(arr, arr + 2);
	if (len == 3 && arr[1] > arr[2])
		ft_swaplong(arr + 1, arr + 2);
	if ((len == 2 || len == 3) && arr[0] > arr[1])
		ft_swaplong(arr, arr + 1);
}

static inline size_t	ft_part_i(long *restrict arr, size_t len)
{
	size_t	i;
	size_t	j;
	long	mid;

	i = 0;
	j = len - 1;
	mid = arr[(len - 1) / 2];
	while (i <= j)
	{
		while (arr[i] > mid)
			i++;
		while (arr[j] < mid)
			j--;
		if (i <= j)
		{
			ft_swaplong(arr + i, arr + j);
			i++;
			j--;
		}
	}
	return (j + 1);
}

static void	ft_sortlong_rec_i(long *restrict arr, size_t len)
{
	size_t	tmp;

	if (len > 3)
	{
		tmp = ft_part_i(arr, len);
		ft_sortlong_rec_i(arr, tmp);
		ft_sortlong_rec_i(arr + tmp, len - tmp);
	}
	if (len == 3 && arr[0] < arr[2])
		ft_swaplong(arr, arr + 2);
	if (len == 3 && arr[1] < arr[2])
		ft_swaplong(arr + 1, arr + 2);
	if ((len == 2 || len == 3) && arr[0] < arr[1])
		ft_swaplong(arr, arr + 1);
}

void	ft_sortlong(long *restrict arr, size_t len, char rev)
{
	if (!rev)
		ft_sortlong_rec(arr, len);
	else
		ft_sortlong_rec_i(arr, len);
}
