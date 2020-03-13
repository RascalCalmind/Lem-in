/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lem_in.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:34:10 by lhageman       #+#    #+#                */
/*   Updated: 2020/03/11 17:22:38 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static int		ft_handle_command_line(t_lemin *list, t_rstr *file)
{
	char	**args;
	char	*command;

	if (ft_strcmp(file->str, "##start") == 0 ||
		ft_strcmp(file->str, "##end") == 0)
	{
		command = ft_strdup(file->str);
		if (!file->str)
			return (ft_free_error_lem_rstr(list, file, 4));
		while (file->str[0] == '#')
			file = file->next;
		args = ft_strsplit(file->str, ' ');
		if ((ft_strcmp(command, "##start") == 0 && list->start != NULL) ||
			(ft_strcmp(command, "##end") == 0 && list->end != NULL))
			ft_error(ERR_DOUBLE_COMMANDS);
		else if (ft_strcmp(command, "##start") == 0)
			list->start = ft_strdup(args[0]);
		else if (ft_strcmp(command, "##end") == 0)
			list->end = ft_strdup(args[0]);
		if (list->start && list->end && ft_strcmp(list->start, list->end) == 0)
			ft_error(ERR_DOUBLE_COMMANDS);
		ft_free_char_arr(args, 4);
		free(command);
		return (1);
	}
	return (0);
}

static int		ft_create_lists(t_lemin *list, t_rstr *file)
{
	list->ants = ft_atoi(file->str);
	if (list->ants <= 0 || ft_check_int(file->str) != 0)
		return (ft_free_error_lem_rstr(list, file, 1));
	file = file->next;
	while (file->next != NULL)
	{
		if (file->str[0] == '#' && file->str[1] != '#')
			;
		else if (ft_is_command(file->str))
			ft_handle_command_line(list, file);
		else if (ft_contains(file->str, ' ') == 2)
		{
			if (!ft_store_room(list, file))
				return (-1);
		}
		else if (list->end == NULL || list->start == NULL)
			return (ft_free_error_lem_rstr(list, file, 4));
		else if (ft_connection(file->str, list) < 0)
			return (ft_free_error_lem_rstr(list, file, 2));
		file = file->next;
	}
	return (1);
}

static void		ft_lem_flags(int argc, char **argv, t_lemin *lemin)
{
	if (argc <= 1)
		return ;
	if ((ft_strcmp(argv[1], "-l") == 0 && lemin->lines > 0) ||\
		(ft_strcmp(argv[1], "-pl") == 0 && lemin->lines > 0) ||\
		(ft_strcmp(argv[1], "-lp") == 0 && lemin->lines > 0))
		ft_printf("Amount of lines used: %i\n", lemin->lines);
	if ((ft_strcmp(argv[1], "-p") == 0 && lemin->lines == -3) ||\
		(ft_strcmp(argv[1], "-pl") == 0 && lemin->lines == -3) ||\
		(ft_strcmp(argv[1], "-lp") == 0 && lemin->lines == -3))
		ft_print_paths(lemin, lemin->max_flow);
}

static t_lemin	*ft_lem_in(t_rstr *file)
{
	t_lemin	*lemin;

	lemin = ft_create_lemin(file);
	if (lemin == NULL || lemin->rooms < 2)
	{
		ft_free_rstr(file);
		ft_free_lemin(lemin);
		ft_error(lemin->rooms < 2 ? ERR_INVALID_ROOM_COUNT : ERR_MEM);
		return (NULL);
	}
	if (ft_create_lists(lemin, file) == -1)
		return (NULL);
	lemin->max_flow = ft_max_flow(lemin);
	if (lemin->max_flow <= 0)
	{
		if (file)
			ft_free_rstr(file);
		if (lemin)
			ft_free_lemin(lemin);
		ft_error(ERR_NO_PATHS);
		return (NULL);
	}
	ft_print_rstr(file);
	return (lemin);
}

int				main(int argc, char **argv)
{
	t_lemin		*lemin;
	t_rstr		*file;

	lemin = NULL;
	file = ft_read_file();
	if (!file)
		return (ft_error(ERR_FILE));
	lemin = ft_lem_in(file);
	if (lemin == NULL)
		return (-1);
	ft_lem_flags(argc, argv, lemin);
	lemin->lines = ft_move_ants(lemin);
	ft_lem_flags(argc, argv, lemin);
	if (file)
		ft_free_rstr(file);
	if (lemin)
		ft_free_lemin(lemin);
	return (0);
}
