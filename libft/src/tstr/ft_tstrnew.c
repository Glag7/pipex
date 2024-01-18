/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:38:32 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/29 20:06:11 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str	ft_tstrnew(char *s, size_t len)
{
	t_str	tstr;

	if (len == (size_t) -1)
		len = ft_strlen(s);
	tstr = (t_str){s, len};
	return (tstr);
}
