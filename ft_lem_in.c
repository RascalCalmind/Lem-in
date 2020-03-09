/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lem_in.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:34:10 by lhageman       #+#    #+#                */
/*   Updated: 2020/03/09 17:38:29 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int		ft_free_error_lem_rstr(t_lemin *list, t_rstr *file, int i)
{
	if (i == 1)
		ft_dprintf(STDERR_FILENO, "No ants :(\n");
	if (i == 2)
		ft_dprintf(STDERR_FILENO, "No ants or connections are invalid!\n");
	if (i == 3)
		ft_dprintf(STDERR_FILENO, "Error in coordinates of room\n");
	if (i == 4)
		ft_dprintf(STDERR_FILENO, "Error in saving start or end room\n");
	ft_free_rstr(file);
	ft_free_lemin(list);
	while (1)
		;
	return (-1);
}

int		ft_handle_command_line(t_lemin *list, t_rstr *file)
{
	char **args;
	char *command;

	if (ft_strcmp(file->str, "##start") == 0 ||
		ft_strcmp(file->str, "##end") == 0)
	{
		command = ft_strdup(file->str);
		file = file->next;
		if (!file->str)
			return (ft_free_error_lem_rstr(list, file, 4));
		args = ft_strsplit(file->str, ' ');
		if ((ft_strcmp(command, "##start") == 0 && list->start != NULL) ||
			(ft_strcmp(command, "##end") == 0 && list->end != NULL))
			ft_error(ERR_DOUBLE_COMMANDS);
		else if (ft_strcmp(command, "##start") == 0)
			list->start = ft_strdup(args[0]);
		else if (ft_strcmp(command, "##end") == 0)
			list->end = ft_strdup(args[0]);
		ft_free_char_arr(args, 4);
		free(command);
		return (1);
	}
	return (0);
}

int		ft_create_lists(t_lemin *list, t_rstr *file)
{
	if (ft_check_int(file->str) != 0)
		return (ft_free_error_lem_rstr(list, file, 1));
	else
	{
		list->ants = ft_atoi(file->str);
		if (list->ants <= 0)
			return (ft_free_error_lem_rstr(list, file, 1));
		file = file->next;
	}
	while (file->next != NULL)
	{
		if (ft_strncmp(file->str, "##", 2) == 0)
		{
			if (ft_handle_command_line(list, file) == -1)
				return (-1);
			file = file->next;
		}
		if (ft_contains(file->str, ' ') == 2)
		{
			if (!ft_store_room(list, file))
				return (-1);
		}
		else
		{
			// ft_printf("ants: %i \t start: %s \t end: %s\n", list->ants, list->start, list->end);
			if (list->end == NULL || list->start == NULL)
				return (ft_free_error_lem_rstr(list, file, 4));
			if (ft_connection(file->str, list) < 0)
				return (ft_free_error_lem_rstr(list, file, 2));
		}
		file = file->next;
	}
	return (1);
}

void	ft_lem_flags(int argc, char **argv, t_lemin *lemin, int maxflow, int lines)
{
	if (argc <= 1)
		return ;	
	if ((ft_strcmp(argv[1], "-l") == 0 && lines > 0) ||\
		(ft_strcmp(argv[1], "-pl") == 0 && lines > 0) ||\
		(ft_strcmp(argv[1], "-lp") == 0 && lines > 0))
		ft_printf("Amount of lines used: %i\n", lines);
	if ((ft_strcmp(argv[1], "-p") == 0 && lines == -3) ||\
		(ft_strcmp(argv[1], "-pl") == 0 && lines == -3) ||\
		(ft_strcmp(argv[1], "-lp") == 0 && lines == -3))
		ft_print_paths(lemin, maxflow);
}

int		main(int argc, char **argv)
{
	t_rstr		*file;
	t_lemin		*lemin;
	int			rooms;
	int			max_flow;
	int			lines;

	rooms = 0;
	lines = -3;
	file = ft_read_file();
	if (!file)
		return (ft_error(ERR_MEM));
	lemin = ft_create_lemin(file);
	rooms = lemin->rooms;
	if (lemin == NULL || rooms < 2)
	{
		ft_free_rstr(file);
		ft_free_lemin(lemin);
		return (ft_error(rooms < 2 ? ERR_INVALID_ROOM_COUNT : ERR_MEM));
	}
	if (ft_create_lists(lemin, file) == -1)
		return (-1);
	max_flow = ft_max_flow(lemin);
	if (max_flow <= 0)
	{
		if (file)
			ft_free_rstr(file);
		if (lemin)
			ft_free_lemin(lemin);
		return (ft_error(ERR_NO_PATHS));
	}
	ft_print_rstr(file);
	ft_lem_flags(argc, argv, lemin, max_flow, lines);
	lines = place_ants(lemin);
	ft_lem_flags(argc, argv, lemin, max_flow, lines);
	if (file)
		ft_free_rstr(file);
	if (lemin)
		ft_free_lemin(lemin);
	// while (1)
	// 	continue;
	return (0);
}
