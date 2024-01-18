/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:11:32 by glaguyon          #+#    #+#             */
/*   Updated: 2024/01/17 18:32:33 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exit_malloc(int fd_stdin, char *name)
{
	dup2(fd_stdin, 0);
	close(fd_stdin);
	ft_perror("pipex", "malloc", "exploded");
	if (*name)
		unlink(name);
	exit(ERR_AINTNOWAY);
}

static int	pipex(t_args *cmds, char *out, char **envp)
{
	int		i;
	int		len;
	int		*pipes;
	pid_t	*pids;

	pipes = setup_pipe(cmds, &len, &i, &pids);
	if (pipes == NULL)
		return (ERR_PIPE);
	while (cmds[i])
	{
		pids[i] = fork();
		if (pids[i] < 0)
			break ;
		if (pids[i] == 0)
		{
			if ((cmds[i + 1] == NULL && open_out(out, 0, pipes, len))
				|| (dup_pipes(pipes, i, len)))
				clean_exit(cmds, pipes, pids);
			if (cmds[i][0])
				execve(cmds[i][0], cmds[i], envp);
			clean_exit(cmds, pipes, pids);
		}
		i++;
	}
	return (end_pipe(pipes, i, len, pids));
}

static int	start_pipex(char **argv, char **envp, int argc)
{
	char	**path;
	t_args	*cmds;
	int		fd;
	int		fd_in;
	char	name[52];

	ft_bzero(name, 52);
	check_quotes(argv, 0);
	fd = open_p(argv[0]);
	argv += 1;
	path = find_path(envp, fd);
	fd_in = dup_p(0, -1, path, -1);
	dup_p(fd, 0, path, fd_in);
	cmds = find_cmd(argv, path, argc);
	ft_freearr(path);
	close(fd);
	if (cmds == NULL)
		exit_malloc(fd_in, name);
	close(fd_in);
	fd_in = pipex(cmds, argv[argc], envp);
	clean_all(cmds, fd_in, name);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	res;

	if (argc != 5)
	{
		ft_perror("pipex", 0, "give 4 args");
		return (ERR_NOARGS);
	}
	else
		res = start_pipex(argv + 1, envp, argc - 3);
	return (res);
}
