/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:38:37 by glaguyon          #+#    #+#             */
/*   Updated: 2024/01/17 17:37:14 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **envp, int fd)
{
	char	**pathes;

	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (*envp == NULL)
	{
		ft_perror("pipex", 0, "cannot find path");
		close(fd);
		exit(ERR_NOPATH);
	}
	pathes = ft_split(*envp + 5, ':');
	if (pathes == NULL)
	{
		ft_perror("pipex", "malloc", "exploded");
		close(fd);
		exit(ERR_AINTNOWAY);
	}
	return (pathes);
}

static char	**not_found(char **args, char exists)
{
	if (*args)
	{
		if (!exists)
			ft_perror("pipex", "command not found", *args);
		else
			ft_perror("pipex", "permission denied", *args);
		ft_freearr(args);
		args = malloc(sizeof(char *));
		if (args)
			*args = NULL;
	}
	else
		ft_perror("pipex", "permission denied", "");
	return (args);
}

static char	**add_path(char **args, char *str)
{
	free(*args);
	*args = str;
	return (args);
}

static t_args	get_cmd(char *arg, char **path)
{
	char	**args;
	char	*str;
	char	exists;

	args = special_split(arg);
	if (args == NULL)
		return (NULL);
	exists = *args && !access(*args, F_OK);
	if (*args && !access(*args, X_OK))
		return (args);
	while (*path && *args)
	{
		str = ft_pathjoin(*path, *args);
		if (str == NULL)
		{
			ft_freearr(args);
			return (NULL);
		}
		exists += !access(str, F_OK);
		if (!access(str, X_OK))
			return (add_path(args, str));
		free(str);
		path++;
	}
	return (not_found(args, exists));
}

t_args	*find_cmd(char **argv, char **path, int argc)
{
	int		i;
	t_args	*cmds;

	i = 0;
	cmds = malloc((argc + 1) * sizeof(t_args));
	if (cmds == NULL)
		return (NULL);
	while (i < argc)
	{
		cmds[i] = get_cmd(argv[i], path);
		if (cmds[i] == NULL)
		{
			ft_delarr(cmds, &ft_freearr);
			return (NULL);
		}
		i++;
	}
	cmds[argc] = NULL;
	return (cmds);
}
