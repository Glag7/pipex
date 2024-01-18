/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:55:14 by glaguyon          #+#    #+#             */
/*   Updated: 2024/01/17 19:22:56 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_perror(char *name, char *name2, char *error)
{
	size_t	tmp;

	tmp = ft_strlen(name);
	write(2, name, tmp);
	write(2, ": ", 2);
	if (name2)
	{
		tmp = ft_strlen(name2);
		write(2, name2, tmp);
		write(2, ": ", 2);
	}
	tmp = ft_strlen(error);
	write(2, error, tmp);
	write(2, "\n", 1);
}

char	*ft_pathjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc((len1 + len2 + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, len1);
	str[len1] = '/';
	ft_memcpy(str + len1 + 1, s2, len2 + 1);
	return (str);
}

int	open_p(char *name)
{
	int	fd;
	int	pipefd[2];

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_perror("pipex", "file", strerror(errno));
		if (pipe(pipefd) == -1)
		{
			ft_perror("pipex", "pipe", strerror(errno));
			exit(ERR_FNF);
		}
		close(pipefd[1]);
		fd = pipefd[0];
	}
	return (fd);
}

void	clean_all(t_args *cmds, int err, char *name)
{
	ft_delarr(cmds, &ft_freearr);
	if (*name)
		unlink(name);
	if (err)
		exit(ERR_PIPE);
}

int	dup_p(int fda, int fdb, char **path, int fd_free)
{
	int	fd;

	if (fdb < 0)
		fd = dup(fda);
	else
		fd = dup2(fda, fdb);
	if (fd < 0)
	{
		if (fd_free >= 0)
			close(fd_free);
		if (fda > 2)
			close(fd);
		ft_freearr(path);
		ft_perror("pipex", "dup", strerror(errno));
		exit(ERR_DUP);
	}
	return (fd);
}
