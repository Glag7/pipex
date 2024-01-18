/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:03:32 by glaguyon          #+#    #+#             */
/*   Updated: 2024/01/17 18:25:38 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft/hdr/libft.h"

# define WSPACE "\f\n\r\t\v "

# define ERR_NOARGS 1
# define ERR_NOPATH 2
# define ERR_AINTNOWAY 3
# define ERR_FNF 4
# define ERR_DUP 5
# define ERR_WR 6
# define ERR_QUOTE 7
# define ERR_PIPE 8

typedef char **	t_args;

//start
char	**find_path(char **envp, int fd);
t_args	*find_cmd(char **argv, char **path, int argc);

//utils
void	ft_perror(char *name, char *name2, char *error);
char	*ft_pathjoin(char const *s1, char const *s2);
int		open_p(char *name);
void	clean_all(t_args *cmds, int err, char *name);
int		dup_p(int fda, int fdb, char **path, int fd_free);

//here_doc
int		here_doc(char *limiter, char *name);

//gen_file
int		open_file(char *name);

//special_split
char	**special_split(char *s);

//check_quotes
void	check_quotes(char **argv, char here_doc);

//pipex
void	close_pipes(int *pipes, int n);
void	waitpid_all(pid_t *pids, int i, int len);
char	open_out(char *name, char append, int *pipes, int len);
char	dup_pipes(int *pipes, int i, int len);

//pipex_misc
int		*setup_pipe(t_args *cmds, int *len, int *i, pid_t **pids);
int		end_pipe(int *pipes, int i, int len, pid_t *pids);
void	clean_exit(t_args *cmds, int *pipes, pid_t *pids);

#endif
