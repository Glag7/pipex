/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_split_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:44:55 by glaguyon          #+#    #+#             */
/*   Updated: 2024/01/17 18:26:57 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static size_t	ft_count_words(const char *s)
{
	char	isword;
	char	insub;
	size_t	count;
	char	c;

	isword = 1;
	insub = 0;
	count = 0;
	c = *s;
	while (c)
	{
		if (ft_in(c, WSPACE) == -1)
		{
			if ((c == '\'' || c == '\"') && c == insub)
				insub = 0;
			else if ((c == '\'' || c == '\"') && insub == 0)
				insub = c;
			count += isword;
			isword = 0;
		}
		else if (insub == 0)
			isword = 1;
		c = *++s;
	}
	return (count);
}

static size_t	get_word_len(char *s)
{
	size_t	len;
	char	insub;
	char	c;

	insub = 0;
	len = 0;
	c = *s;
	while (c)
	{
		if (insub == 0 && ft_in(c, WSPACE) != -1)
			break ;
		if ((c == '\'' || c == '\"') && c == insub)
			insub = 0;
		else if ((c == '\'' || c == '\"') && insub == 0)
			insub = c;
		else
			len++;
		s++;
		c = *s;
	}
	return (len);
}

static size_t	fill_word(char *dst, char *src)
{
	size_t	i;
	char	insub;
	char	c;

	i = 0;
	insub = 0;
	c = *src;
	while (c)
	{
		if (insub == 0 && ft_in(c, WSPACE) != -1)
			break ;
		if ((c == '\'' || c == '\"') && c == insub)
			insub = 0;
		else if ((c == '\'' || c == '\"') && insub == 0)
			insub = c;
		else
		{
			*dst = src[i];
			dst++;
		}
		i++;
		c = src[i];
	}
	return (i);
}

static char	*get_next_word(char **s)
{
	size_t	len;
	char	*str;

	while (**s && ft_in(**s, WSPACE) != -1)
		(*s)++;
	len = get_word_len(*s);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	*s += fill_word(str, *s);
	return (str);
}

char	**special_split(char *s)
{
	char	**strs;
	size_t	word_count;
	size_t	i;

	word_count = ft_count_words(s);
	strs = malloc((word_count + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		strs[i] = get_next_word(&s);
		if (strs[i] == NULL)
		{
			ft_freearr(strs);
			return (NULL);
		}
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
