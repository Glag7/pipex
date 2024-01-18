/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:32:37 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/20 04:46:25 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*sdup;
	size_t	*sdup_long;
	size_t	*s_long;

	sdup = malloc((n + 1) * sizeof(char));
	if (sdup == NULL)
		return (NULL);
	sdup_long = (size_t *) sdup;
	s_long = (size_t *) s;
	i = 0;
	while (i < n / sizeof(size_t))
	{
		sdup_long[i] = s_long[i];
		i++;
	}
	i *= sizeof(size_t);
	while (i < n)
	{
		sdup[i] = s[i];
		i++;
	}
	sdup[i] = '\0';
	return (sdup);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	char	c;
	char	*str;

	len = 0;
	i = 0;
	c = *s1;
	while (ft_in(c, set) != -1 && c)
	{
		s1++;
		c = *s1;
	}
	while (c)
	{
		i++;
		if (ft_in(c, set) == -1)
			len = i;
		c = s1[i];
	}
	str = ft_strndup(s1, len);
	return (str);
}
