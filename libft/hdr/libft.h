/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:14:44 by glaguyon          #+#    #+#             */
/*   Updated: 2024/01/12 21:32:02 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_str
{
	char	*s;
	size_t	len;
}	t_str;

//arr
ssize_t	ft_chrarr_int(const int *restrict arr, int tofind, size_t len);
ssize_t	ft_chrarr_len(const void *restrict arr, const void *restrict tofind,
			size_t flen, size_t len);
ssize_t	ft_chrarr_long(const ssize_t *restrict arr, ssize_t tofind, size_t len);
ssize_t	ft_chrarr_ptr(const void *restrict arr, const void *restrict tofind,
			size_t len,
			char (*cmp)(const void *restrict, const void *restrict));
void	ft_delarr(void *restrict arr, void (del)(void *restrict));
void	ft_delnarr(void *restrict arr, void (del)(void *restrict), size_t n);
void	ft_freearr(void *restrict arr);
void	ft_freenarr(void *restrict arr, size_t n);
void	ft_sortint(int *restrict arr, size_t len, char rev);
void	ft_sortlen(void *restrict arr, size_t len, char rev, size_t memlen);
void	ft_sortlong(long *restrict arr, size_t len, char rev);
void	ft_sortptr(void *restrict arr, size_t len, char rev,
			char (*cmp)(void *restrict, void *restrict));
void	ft_swapint(int *a, int *b);
void	ft_swaplen(void *a, void *b, size_t len);
void	ft_swaplong(ssize_t *a, ssize_t *b);
void	ft_swapptr(void *a, void *b);

//char
char	ft_isalnum(int c);
char	ft_isalpha(int c);
char	ft_isascii(int c);
char	ft_isdigit(int c);
char	ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

//file
t_str	ft_gnl_tstr(int fd, size_t bsize);
char	*ft_gnl(int fd, size_t bsize);

//lst
t_list	*ft_lstat(t_list *lst, size_t n);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
t_str	ft_lsttstr_to_tstr(t_list **lst, size_t len, void (del)(void *),
			short (end)(t_str *));
size_t	ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstpop(t_list **lst, void (del)(void *), int n);
char	*ft_lsttstr_to_str(t_list **lst, size_t len, void (del)(void *),
			short (end)(t_str *));

//math
ssize_t	ft_max(ssize_t a, ssize_t b);
ssize_t	ft_min(ssize_t a, ssize_t b);
ssize_t	ft_powi(ssize_t x, size_t n);
size_t	ft_sqrti(size_t n);

//mem
void	ft_bspace(void *s, size_t n);
void	ft_bzchar(void *s, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

//print
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(ssize_t n, int fd);
void	ft_putnbrbase_fd(ssize_t n, int fd, char *base);
void	ft_putstr_fd(char *s, int fd);

//str
ssize_t	ft_atoi(const char *nptr);
ssize_t	ft_atoibase(const char *nptr, const char *base);
ssize_t	ft_in(char c, const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	**ft_split(char const *s, char c);
char	**ft_split_set(char const *s, const char *c);
char	*ft_itoa(ssize_t n);
char	*ft_itoabase(ssize_t n, const char *base);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//tstr
t_list	*ft_tstr_to_lst(t_str tstr, char *charset);
t_str	ft_tstrjoin(t_str s1, t_str s2);
short	ft_iseol(t_str *tstr);
t_str	ft_tstr_dupstr(char *s, size_t len);
t_str	ft_tstrnew(char *str, size_t len);
void	ft_tstrfree(void *tstr);
void	ft_tstrdel(void *tstr);

#endif
