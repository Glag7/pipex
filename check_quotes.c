/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:12:38 by glaguyon          #+#    #+#             */
/*   Updated: 2024/01/13 21:20:26 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static ssize_t	find_end(char *s)
{
	ssize_t	i;
	char	c;
	char	curr;

	c = *s;
	i = 1;
	curr = s[1];
	while (curr)
	{
		i++;
		if (curr == c)
			return (i);
		curr = s[i];
	}
	return (-1);
}

static char	bad_quotes(char *s)
{
	char	c;
	ssize_t	i;
	ssize_t	tmp;

	i = 0;
	c = *s;
	while (c)
	{
		if (c == '\'' || c == '\"')
		{
			tmp = find_end(s + i);
			if (tmp == -1)
				return (1);
			i += tmp;
		}
		else
			i++;
		c = s[i];
	}
	return (0);
}

void	check_quotes(char **argv, char here_doc)
{
	int	i;

	i = 0;
	argv += 1 + here_doc;
	while (argv[i + 1])
	{
		if (bad_quotes(argv[i]))
		{
			ft_perror("pipex", 0, "uneven number of quotes");
			exit(ERR_QUOTE);
		}
		i++;
	}
}
