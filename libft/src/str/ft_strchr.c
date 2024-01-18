/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:21:50 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/02 15:39:40 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	curr;

	c = (char) c;
	curr = *s;
	while (curr)
	{
		if (curr == c)
			return ((char *) s);
		s++;
		curr = *s;
	}
	if (c == '\0')
		return ((char *) s);
	return ((char *) 0);
}
