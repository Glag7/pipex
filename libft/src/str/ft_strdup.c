/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:08:56 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/02 14:44:22 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*sdup;
	size_t	*sdup_long;
	size_t	*s_long;

	len = ft_strlen(s) + 1;
	sdup = malloc(len * sizeof(char));
	if (sdup == NULL)
		return (NULL);
	sdup_long = (size_t *) sdup;
	s_long = (size_t *) s;
	i = 0;
	while (i < len / sizeof(size_t))
	{
		sdup_long[i] = s_long[i];
		i++;
	}
	i *= sizeof(size_t);
	while (i < len)
	{
		sdup[i] = s[i];
		i++;
	}
	return (sdup);
}
