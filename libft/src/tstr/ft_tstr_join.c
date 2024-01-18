/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:55:39 by glaguyon          #+#    #+#             */
/*   Updated: 2024/01/13 01:24:56 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str	ft_tstrjoin(t_str s1, t_str s2)
{
	t_str	tstr;

	tstr.s = malloc((s1.len + s2.len + 1) * sizeof(char));
	if (tstr.s == NULL)
		return ((t_str){NULL, 0});
	ft_memcpy(tstr.s, s1.s, s1.len);
	ft_memcpy(tstr.s + s1.len, s2.s, s2.len);
	tstr.len = s1.len + s2.len;
	return (tstr);
}
