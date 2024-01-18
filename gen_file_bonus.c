/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_file_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:35:59 by glaguyon          #+#    #+#             */
/*   Updated: 2024/01/17 18:23:03 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	inc_name(char *name)
{
	int		i;
	char	done;

	name++;
	i = 0;
	done = 1;
	while ((i == 0 || !done) && name[i])
	{
		if (name[i] == 'Z')
		{
			name[i] = '0';
			done = 0;
		}
		else
		{
			if (name[i] == 'z')
				name[i] = 'A';
			else if (name[i] == '9')
				name[i] = 'a';
			else
				name[i]++;
			done = 1;
		}
		i++;
	}
}

int	open_file(char *name)
{
	int	fd;

	fd = -1;
	ft_bzchar(name, 52);
	name[1] = 47;
	name[51] = 0;
	name[0] = '.';
	while (fd == -1)
	{
		inc_name(name);
		if (access(name, F_OK))
		{
			fd = open(name, O_CREAT | O_EXCL | O_WRONLY, 0644);
			if (fd == -1 && errno != EEXIST)
			{
				ft_perror("pipex", "here_doc", strerror(errno));
				exit(ERR_FNF);
			}
		}
	}
	return (fd);
}
