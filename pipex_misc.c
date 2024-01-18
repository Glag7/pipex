/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_misc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:50:25 by glaguyon          #+#    #+#             */
/*   Updated: 2024/01/17 18:09:23 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	*gen_pipes(t_args *cmds, int *len, pid_t **pids)
{
	int	i;
	int	*pipes;

	while (cmds[*len])
		(*len)++;
	pipes = malloc(2 * sizeof(int) * (*len - 1));
	if (pipes != NULL)
		*pids = malloc(sizeof(pid_t) * *len);
	if (*pids == NULL)
		free(pipes);
	if (pipes == NULL || *pids == NULL)
		ft_perror("pipex", "malloc", "exploded");
	i = -1;
	while (pipes && ++i < *len - 1)
	{
		if (pipe(pipes + 2 * i) == -1)
		{
			close_pipes(pipes, i * 2);
			free(pipes);
			free(*pids);
			ft_perror("pipex", 0, "error opening pipes");
			return (NULL);
		}
	}
	return (pipes);
}

int	end_pipe(int *pipes, int i, int len, pid_t *pids)
{
	close_pipes(pipes, (len - 1) * 2);
	waitpid_all(pids, i, len);
	free(pipes);
	free(pids);
	return (0);
}

int	*setup_pipe(t_args *cmds, int *len, int *i, pid_t **pids)
{
	int	*pipes;

	*i = 0;
	*len = 0;
	pipes = gen_pipes(cmds, len, pids);
	return (pipes);
}

void	clean_exit(t_args *cmds, int *pipes, pid_t *pids)
{
	ft_delarr(cmds, &ft_freearr);
	free(pipes);
	free(pids);
	exit(ERR_PIPE);
}
