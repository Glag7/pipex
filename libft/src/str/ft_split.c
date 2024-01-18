/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:06:51 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/22 16:20:09 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	word_count;
	short	isword;
	char	curr;

	word_count = 0;
	isword = 1;
	curr = *s;
	while (curr)
	{
		if (curr == c)
			isword = 1;
		else
		{
			word_count += isword;
			isword = 0;
		}
		s++;
		curr = *s;
	}
	return (word_count);
}

static size_t	ft_gotonext(const char *s, char c)
{
	size_t	offset;
	short	isc;
	char	curr;

	curr = *s;
	isc = (*s == c);
	offset = 0;
	while (curr && isc == (curr == c))
	{
		offset++;
		curr = s[offset];
	}
	return (offset);
}

static char	*ft_worddup(const char *s, char c)
{
	char	*word;
	size_t	len;

	len = ft_gotonext(s, c);
	word = malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	word_count;
	size_t	i;

	word_count = ft_count_words(s, c);
	strs = malloc((word_count + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		if (*s != c)
		{
			strs[i] = ft_worddup(s, c);
			if (strs[i] == NULL)
			{
				ft_freearr((void **) strs);
				return (NULL);
			}
			i++;
		}
		s += ft_gotonext(s, c);
	}
	strs[i] = NULL;
	return (strs);
}
