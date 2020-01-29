/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lem_in.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:34:10 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/26 18:36:09 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int	ft_error(int i)
{
	if (i == 1)
		ft_dprintf(2, "Too many arguments given!\n");
	if (i == 2)
		ft_dprintf(2, "Invalid roomname! Can't start with 'L'\n");
	if (i == 3)
		ft_dprintf(2, "Trouble allocating memory\n");
	ft_dprintf(2, "Error\n");
	return (-1);
}

// t_room *create_room(char *line)
// {
// 	char **args;
// 	t_room *room;

// 	room = (t_room *)ft_memalloc(sizeof(t_room *));
// 	room->
// 	args = ft_strsplit(line, ' ');

// }

// int create_start_node(char *line)
// {
// 	char **args;

// 	args = ft_strsplit()
// }

int	ft_read(char **arr)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(STDIN_FILENO, &line) && i < 15000)
	{
		if (ft_strlen(line) > 0)
		{
			arr[i] = malloc(sizeof(char *) * ft_strlen(line));
			arr[i] = ft_strdup(line);
			i += 1;
			if (ft_strlen(arr[i - 1]) > 1 && arr[i - 1][0] == '#'
				&& arr[i - 1][1] != '#')
			{
				free(arr[i - 1]);
				i -= 1;
			}
			else if (ft_strlen(arr[i - 1]) > 1 && arr[i - 1][0] == '#'
				&& arr[i - 1][1] == '#')
			{
				if (ft_strcmp(arr[i - 1], "##start") != 0 &&
					ft_strcmp(arr[i - 1], "##end") != 0)
					return (-1);
			}
		}
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int		ret;
	char	**arr;
	int		j;

	j = 0;
	argv[0] = NULL;
	arr = malloc(sizeof(char **) * 15000);
	if (!arr)
		return (ft_error(3));
	if (argc > 1)
		return (ft_error(1));
	ret = ft_read(arr);
	if (ret < 1)
		return (ft_error(4));
	while (j < ret)
	{
		ft_printf("%s\n", arr[j]);
		j += 1;
	}
	free(arr);
}
