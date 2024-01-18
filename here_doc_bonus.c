/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:36:53 by glaguyon          #+#    #+#             */
/*   Updated: 2024/01/17 18:26:07 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	write_p(int fd, void *line, int fd_close, char *name)
{
	char	res;
	size_t	len;

	if (fd < 3)
	{
		len = ft_strlen((char *) line);
		res = write(fd, (char *) line, len) < 1;
	}
	else
		res = write(fd, ((t_str *)line)->s, ((t_str *)line)->len) < 1;
	if (res)
	{
		if (fd_close > 2)
			close(fd_close);
		if (fd > 2)
		{
			if (line)
				free(((t_str *)line)->s);
			free(line);
		}
		unlink(name);
		ft_perror("pipex", "write", strerror(errno));
		exit(ERR_WR);
	}
}

static void	parse_line_errors(t_str *line, char *limiter, char *name)
{
	if (line == NULL || line->s == NULL)
	{
		unlink(name);
		if (line)
			free(line->s);
		free(line);
		ft_perror("pipex", "malloc", "exploded");
		exit(ERR_AINTNOWAY);
	}
	if (!*(line->s))
	{
		write_p(1, "\n", 1, name);
		write(2, "pipex: warning: here_doc delimited by EOF (wanted '", 51);
		write(2, limiter, ft_strlen(limiter));
		write(2, "')\n", 3);
	}
	free(line->s);
	free(line);
}

static t_str	*here_doc_add(size_t *word_len, t_list **lst, t_str *line)
{
	t_list	*tmp;

	*word_len += line->len;
	tmp = ft_lstnew(line);
	if (tmp == NULL)
	{
		ft_tstrdel(line);
		return (NULL);
	}
	ft_lstadd_back(lst, tmp);
	if (line->len != 0 && line->s[line->len - 1] == '\n')
	{
		line = malloc(sizeof(t_str));
		if (line)
			*line = ft_lsttstr_to_tstr(lst, *word_len, &ft_tstrdel, 0);
	}
	return (line);
}

static t_str	*here_doc_loop(void)
{
	t_str	*line;
	size_t	word_len;
	t_list	*lst;

	word_len = 0;
	lst = NULL;
	line = malloc(sizeof(t_str));
	if (line != NULL)
		*line = ft_gnl_tstr(0, 128);
	if (line == NULL || line->s == NULL || line->len == 0)
		return (line);
	while (1)
	{
		line = here_doc_add(&word_len, &lst, line);
		if (lst == NULL || line == NULL)
			break ;
		line = malloc(sizeof(t_str));
		if (line)
			*line = ft_gnl_tstr(0, 128);
	}
	ft_lstclear(&lst, &ft_tstrdel);
	return (line);
}

int	here_doc(char *limiter, char *name)
{
	int		fd;
	t_str	*line;

	fd = open_file(name);
	write_p(1, "here_doc> ", fd, name);
	line = here_doc_loop();
	while (line && line->s && (line->len != ft_strlen(limiter) + 1
			|| ft_strncmp(limiter, line->s, ft_strlen(limiter))) && line->len)
	{
		write_p(fd, line, fd, name);
		free(line->s);
		free(line);
		write_p(1, "here_doc> ", fd, name);
		line = here_doc_loop();
	}
	close(fd);
	parse_line_errors(line, limiter, name);
	if (access(name, R_OK))
	{
		unlink(name);
		ft_perror("pipex", "here_doc", "tempfile corruption detected");
		exit(ERR_FNF);
	}
	fd = open_p(name);
	return (fd);
}
