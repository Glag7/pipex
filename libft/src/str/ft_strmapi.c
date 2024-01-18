/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:45:51 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/21 19:05:33 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*sdup;
	size_t	i;
	size_t	len;

	if (f == NULL)
	{
		sdup = ft_strdup(s);
		return (sdup);
	}
	len = ft_strlen(s);
	sdup = malloc((len + 1) * sizeof(char));
	if (sdup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sdup[i] = f(i, s[i]);
		i++;
	}
	sdup[i] = 0;
	return (sdup);
}
