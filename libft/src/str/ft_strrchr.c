/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:34:32 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/02 15:37:28 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	curr;
	char	*ptr;

	c = (char) c;
	curr = *s;
	ptr = (char *) 0;
	while (curr)
	{
		if (curr == c)
			ptr = (char *) s;
		s++;
		curr = *s;
	}
	if (curr == c)
		return ((char *) s);
	return (ptr);
}
