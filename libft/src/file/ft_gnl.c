/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:34:26 by glaguyon          #+#    #+#             */
/*   Updated: 2024/01/12 22:47:41 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free1024(t_list **readed)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		ft_lstclear(readed + i, &ft_tstrdel);
		readed[i] = 0;
		i++;
	}
	return (NULL);
}

static char	*ft_freegnl(t_list **readed, int fd)
{
	if (fd < -1024)
		ft_free1024(readed);
	else
		ft_lstclear(readed - fd - 1, &ft_tstrdel);
	return (NULL);
}

static t_list	*ft_gnl_loop(size_t *len, size_t bsize, int fd)
{
	t_str	line;
	ssize_t	read_size;
	t_list	*tmp;

	read_size = 0;
	line = (t_str){malloc(bsize * sizeof(char)), 0};
	if (line.s == NULL)
		*len = (size_t)1 << 62;
	else
		read_size = read(fd, line.s, bsize);
	if (read_size <= 0)
	{
		free(line.s);
		return (NULL);
	}
	line.len = read_size;
	tmp = ft_tstr_to_lst(line, "\n");
	if (tmp == NULL)
		*len = -1;
	else if (ft_iseol(tmp->content))
		*len += ((t_str *)tmp->content)->len;
	else
		*len += read_size;
	free(line.s);
	return (tmp);
}

static size_t	ft_gnl_file(t_list **readed, t_list **lst, int fd,
	size_t bsize)
{
	size_t	len;
	t_list	*tmp;
	t_list	*end;

	len = 0;
	end = *lst;
	if (end == NULL)
		lst = readed + fd;
	while (len == 0 || !ft_iseol(tmp->content))
	{
		tmp = ft_gnl_loop(&len, bsize, fd);
		if (tmp == NULL)
			break ;
		if (*lst == NULL)
			*lst = tmp;
		else
			ft_lstadd_back(&end, tmp);
		end = tmp;
	}
	if (len == (size_t)1 << 62)
		ft_free1024(readed);
	else if (readed[fd] == NULL)
		readed[fd] = ft_tstr_to_lst((t_str){0, 0}, "saucisse");
	return (len);
}

char	*ft_gnl(int fd, size_t bsize)
{
	static t_list	*readed[1024] = {NULL};
	t_list			*tmp;
	char			*line;
	size_t			len;

	if (fd < 0)
	{
		ft_freegnl(readed, fd);
		return (NULL);
	}
	len = 0;
	tmp = readed[fd];
	while (tmp)
	{
		len += ((t_str *)tmp->content)->len;
		if (tmp->next == NULL || ft_iseol((t_str *)(tmp->content)))
			break ;
		tmp = tmp->next;
	}
	if (!tmp || !ft_iseol((t_str *)(tmp->content)))
		len += ft_gnl_file(readed, &tmp, fd, bsize);
	line = ft_lsttstr_to_str(readed + fd, len, &ft_tstrdel, &ft_iseol);
	if (line == NULL)
		ft_free1024(readed);
	return (line);
}
