/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr_dupstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:33:45 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/19 21:46:58 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str	ft_tstr_dupstr(char *s, size_t len)
{
	t_str	tstr;
	char	*str;

	if (len == (size_t) -1)
		len = ft_strlen(s);
	str = malloc(len * sizeof(char));
	if (str)
		ft_memcpy(str, s, len);
	tstr = (t_str){str, len};
	return (tstr);
}
