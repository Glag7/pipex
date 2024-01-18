/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:11:32 by glaguyon          #+#    #+#             */
/*   Updated: 2024/01/17 18:24:16 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	exit_malloc(int fd_stdin, char *name)
{
	dup2(fd_stdin, 0);
	close(fd_stdin);
	ft_perror("pipex", "malloc", "exploded");
	if (*name)
		unlink(name);
	exit(ERR_AINTNOWAY);
}

static int	pipex(t_args *cmds, char *out, char append, char **envp)
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
			if ((cmds[i + 1] == NULL && open_out(out, append, pipes, len))
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

static int	start_pipex(char **argv, char **envp, char *limiter, int argc)
{
	char	**path;
	t_args	*cmds;
	int		fd;
	int		fd_in;
	char	name[52];

	ft_bzero(name, 52);
	check_quotes(argv, !!limiter);
	if (limiter)
		fd = here_doc(limiter, name);
	else
		fd = open_p(argv[0]);
	argv += 1 + !!limiter;
	path = find_path(envp, fd);
	fd_in = dup_p(0, -1, path, -1);
	dup_p(fd, 0, path, fd_in);
	cmds = find_cmd(argv, path, argc);
	ft_freearr(path);
	close(fd);
	if (cmds == NULL)
		exit_malloc(fd_in, name);
	close(fd_in);
	fd_in = pipex(cmds, argv[argc], !!limiter, envp);
	clean_all(cmds, fd_in, name);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	res;

	if (argc < 5)
	{
		ft_perror("pipex", 0, "give at least 4 args");
		return (ERR_NOARGS);
	}
	if (argv[1] && ft_strncmp(argv[1], "here_doc", -1) == 0)
	{
		if (argc < 6)
		{
			ft_perror("pipex", "here_doc", "give at least 5 args");
			return (ERR_NOARGS);
		}
		res = start_pipex(argv + 1, envp, argv[2], argc - 4);
	}
	else
		res = start_pipex(argv + 1, envp, NULL, argc - 3);
	return (res);
}
