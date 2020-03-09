/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_file.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 17:29:34 by wmisiedj       #+#    #+#                */
/*   Updated: 2020/03/09 16:21:52 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_lem_in.h"

static	ft_read(t_rstr *file)
{
	char	*line;
	int		fd;

	fd = STDIN_FILENO;
	// fd = open("./testmaps/err_noant2.txt");
	//fd = open("./testmaps/map4.txt");
	// fd = open("./testmaps/map6.txt");
	// fd = open("./testmaps/map7.txt");
	// fd = open("./testmaps/test_one.txt");
	// fd = open("./testmaps/test_one2.txt");
	// fd = open("./testmaps/test_ten.txt");
	// fd = open("./testmaps/test_ten2.txt");
	// fd = open("./testmaps/test_thousand.txt");
	// fd = open("./testmaps/test_thousand2.txt");
	// fd = open("./testmaps/test_big.txt");
	//fd = open("./testmaps/test_superpos.txt");
	while (get_next_line(fd, &line))
	{
		if (ft_strlen(line) > 0 && line != NULL && line[0])
		{
			file->str = ft_strdup(line);
			if ((file->str[0] == '#' && file->str[1] != '#') ||
				(file->str[0] == '#' && file->str[1] == '#' &&
				!ft_is_command(file->str)))
			{
				free(file->str);
				file->str = NULL;
			}
			if (file->str != NULL)
			{
				file->next = ft_memalloc(sizeof(t_rstr));
				file = file->next;
			}
		}
		if (line != NULL)
			free(line);
		line = NULL;
	}
}

t_rstr		*ft_read_file(void)
{
	t_rstr	*file;

	file = ft_memalloc(sizeof(t_rstr));
	if (!file)
		return (NULL);
	ft_read(file);
	return (file);
}
