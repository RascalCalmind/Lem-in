/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 17:24:47 by lhageman       #+#    #+#                */
/*   Updated: 2019/11/22 16:09:42 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFF_SIZE 20

static int			ft_readloop(int fd, char *buf, t_glist *item, char **line)
{
	int		ret;
	char	*temp;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		temp = ft_strjoin(item->content, buf);
		free(item->content);
		item->content = ft_strdup(temp);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && ft_strlen(item->content) == 0)
		return (0);
	*line = ft_strsub(item->content, 0, ft_strclen(item->content, '\n'));
	temp = ft_strsub(item->content, ft_strlen(*line) + 1, \
	ft_strlen(item->content) - ft_strlen(*line));
	free(item->content);
	item->content = ft_strdup(temp);
	free(temp);
	temp = NULL;
	return (1);
}

static t_glist		*ft_content_sizecheck(int fd, t_glist *start)
{
	t_glist	*temp;
	t_glist	*new;

	while (start != NULL)
	{
		if (start->content_size == (size_t)fd)
			return (start);
		temp = start;
		start = start->next;
	}
	new = ft_glstnew("\0", 1);
	if (new == NULL)
		return (NULL);
	new->content_size = fd;
	temp->next = new;
	return (new);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_glist	*start;
	t_glist			*item;
	int				more;

	item = NULL;
	if (fd < 0 || fd == 1 || line == NULL || BUFF_SIZE <= 0 ||
		read(fd, buf, 0) == -1)
		return (-1);
	if (!start)
	{
		item = ft_glstnew("\0", 1);
		item->content_size = fd;
		start = item;
	}
	else
		item = ft_content_sizecheck(fd, start);
	more = ft_readloop(fd, buf, item, line);
	if (more == -1)
		return (-1);
	if (more == 1)
		return (1);
	ft_strclr(*line);
	return (0);
}
