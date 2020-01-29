/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lem_in.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:34:10 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/25 16:37:06 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int	ft_error(int i)
{
	if (i == 1)
		ft_dprintf(2, "Too many arguments given!\n");
	if (i == 2)
		ft_dprintf(2, "Invalid roomname! Can't start with 'L'\n");
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

int	main(int argc, char **argv)
{
	char *line;
	char *start;
	char *end;
	int s;
	int e;

	s = 0;
	e = 0;
	argv[0] = NULL;
	if (argc > 1)
		return (ft_error(1));
	while (get_next_line(STDIN_FILENO, &line))
	{
		//ft_printf("LINE STDIN: %s\n", line);
		if (line[0] == 'L')
			return (ft_error(2));
		if (ft_strcmp(line, "##start") == 0 && s != 2)
			s = 1;
		if (ft_strcmp(line, "##end") == 0 && e != 2)
			e = 1;
		if (s == 1 && line[0] != '#')
		{
			start = line;
			s = 2;
		}
		if (e == 1 && line[0] != '#')
		{
			end = line;
			e = 2;
		}
	}
	if (!start || !end)
		return (ft_error(3));
	ft_printf("start: %s, end: %s\n", start, end);
	return (0);
}
