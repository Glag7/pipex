/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:46:39 by glaguyon          #+#    #+#             */
/*   Updated: 2024/01/17 18:25:00 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_pipes(int *pipes, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		close(pipes[i]);
		i++;
	}
}

void	waitpid_all(pid_t *pids, int i, int len)
{
	int	j;

	j = 0;
	if (i != len)
		ft_perror("pipex", "fork", strerror(errno));
	while (j < i)
	{
		waitpid(pids[j], 0, 0);
		j++;
	}
}

char	open_out(char *name, char append, int *pipes, int len)
{
	int	fd;

	if (append)
		fd = open(name, O_APPEND | O_WRONLY | O_CREAT, 0644);
	else
		fd = open(name, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (fd < 0 || dup2(fd, 1) == -1)
	{
		close_pipes(pipes, (len - 1) * 2);
		if (fd >= 0)
			close(fd);
		ft_perror("pipex", 0, "problem opening outfile");
		return (1);
	}
	close(fd);
	return (0);
}

char	dup_pipes(int *pipes, int i, int len)
{
	if (i != len - 1 && dup2(pipes[2 * i + 1], 1) == -1)
	{
		close_pipes(pipes, (len - 1) * 2);
		ft_perror("pipex", 0, "error while piping");
		return (ERR_PIPE);
	}
	if (i && dup2(pipes[2 * (i - 1)], 0) == -1)
	{
		close_pipes(pipes, (len - 1) * 2);
		ft_perror("pipex", 0, "error while piping");
		return (ERR_PIPE);
	}
	close_pipes(pipes, 2 * (len - 1));
	return (0);
}
