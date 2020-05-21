/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_file.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 17:29:34 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/05/21 12:08:32 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_lem_in.h"
#include <fcntl.h>

static int	ft_read(t_rstr *file, int fd)
{
	char	*line;
	int		ret;

	ret = 1;
	line = NULL;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret > 0 && line != NULL)
		{
			file->str = ft_strdup(line);
			file->next = ft_memalloc(sizeof(t_rstr));
			if (!file->str || !file->next)
			{
				free(line);
				return (ERR_MEM);
			}
			file = file->next;
			free(line);
			line = NULL;
		}
	}
	return (1);
}

t_rstr		*ft_read_file(void)
{
	t_rstr	*file;
	int		fd;
	int		ret;

	ret = 1;
	fd = STDIN_FILENO;
	if (read(fd, NULL, 1) == 0)
	{
		ft_error(ERR_FILE);
		return (NULL);
	}
	file = ft_memalloc(sizeof(t_rstr));
	if (!file)
	{
		ft_error(ERR_MEM);
		return (NULL);
	}
	ret = ft_read(file, fd);
	if (ret != 1)
	{
		ft_free_rstr(file);
		ft_error(ret);
		return (NULL);
	}
	return (file);
}
