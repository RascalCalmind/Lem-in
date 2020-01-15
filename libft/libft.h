/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 22:17:20 by lhageman       #+#    #+#                */
/*   Updated: 2019/12/29 15:00:15 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_glist
{
	void			*content;
	size_t			content_size;
	struct s_glist	*next;
}					t_glist;

void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				ft_putnbr(long long nb);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				ft_strclr(char *s);

char				*ft_itoa(int n);
char				*ft_strdup(const char *s1);
char				*strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnew(size_t len);
char				*ft_strnjoin(const char *s1, const char *s2, int len1,
					int len2);

size_t				ft_strlen(const char *s);
int					ft_chararrlen(char **arr);
int					ft_intarrlen(int *arr);

int					ft_isspace(char c);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);

int					get_next_line(const int fd, char **line);
char				**ft_strsplit(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strsub(char const *s, unsigned int strart, size_t len);
size_t				ft_strclen(const char *s, int c);
t_glist				*ft_glstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *restrict dst, const void *restrict src,
					size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *s, int c);

#endif
