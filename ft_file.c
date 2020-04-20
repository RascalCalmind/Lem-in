/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_file.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 17:29:34 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/04/16 12:10:27 by Lotte         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_lem_in.h"
#include <fcntl.h>

static void	ft_read(t_rstr *file, int fd)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		if (line != NULL)
		{
			// if (!((line[0] == '#' && line[1] != '#') ||
			// 	(line[0] == '#' && line[1] == '#' &&
			// 	!ft_is_command(line))))
			// {
			ft_printf("%s\n", line);
			file->str = ft_strdup(line);
			file->next = ft_memalloc(sizeof(t_rstr));
			file = file->next;
			// }
		}
		if (line != NULL)
			free(line);
		line = NULL;
	}
}

t_rstr		*ft_read_file(void)
{
	t_rstr	*file;
	int		fd;

	fd = STDIN_FILENO;
	// fd = open("./testmaps/err_noant2.txt");
	// fd = open("./testmaps/err_noant.txt");
	// fd = open("./testmaps/err_nostart.txt", O_RDONLY);
	// ft_printf("hi wendell\n");
	// fd = open("./testmaps/map7.txt");
	// fd = open("./testmaps/test_one.txt");
	// fd = open("./testmaps/test_one2.txt");
	// fd = open("./testmaps/test_ten.txt", O_RDONLY);
	// fd = open("./testmaps/test_ten2.txt");
	// fd = open("./testmaps/test_thousand.txt");
	// fd = open("./testmaps/test_thousand2.txt");
	// fd = open("./testmaps/test_big.txt");
	// fd = open("./testmaps/test_superpos.txt", O_RDONLY);
	if (read(fd, NULL, 1) == 0)
		return (NULL);
	file = ft_memalloc(sizeof(t_rstr));
	if (!file)
		return (NULL);
	ft_read(file, fd);
	return (file);
}
