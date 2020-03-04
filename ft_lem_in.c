/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lem_in.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:34:10 by lhageman       #+#    #+#                */
/*   Updated: 2020/03/04 15:12:17 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int		ft_free_error_lem_rstr(t_lemin *list, t_rstr *file)
{
	ft_free_rstr(file);
	ft_free_lemin(list);
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
			return (ft_free_error_lem_rstr(list, file));
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
		return (ft_free_error_lem_rstr(list, file));
	else
	{
		list->ants = ft_atoi(file->str);
		file = file->next;
	}
	while (file->next != NULL)
	{
		//ft_printf("ft_create_lists\t\tfile->str:%s\n", file->str);
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
			if (ft_connection(file->str, list) < 0)
				return (ft_free_error_lem_rstr(list, file));
		}
		file = file->next;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_rstr	*file;
	t_lemin *lemin;
	int		rooms;
	int		max_flow;

	//ft_printf("START");
	rooms = 0;
	// if (argv && argc > 1)
	// 	return (ft_error(ERR_PARAMS));
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
		return (ft_error(ERR_MEM));
	ft_print_lemin(lemin);
	// ft_bfs(lemin, ft_find_room(lemin, lemin->start), ft_find_room(lemin, lemin->end));
	max_flow = ft_max_flow(lemin);
	ft_printf(" -- MAX FLOW --: %d\n", max_flow);
	int j = 0;
	ft_printf("hello :D\n");
	for (int i = 0; i < max_flow; i++)
	{
		if (lemin->paths[i] && lemin->paths[i]->room != NULL)
		{
			ft_printf("paths length: %i\n", lemin->paths[i]->len);
			ft_printf("FOUND A PATH [%i]: ", i);
			while (j <= lemin->paths[i]->len)
			{
				ft_printf("%s->", lemin->paths[i]->room[j]->name);
				j += 1;
			}
			ft_printf("%s\n", lemin->end);
			j = 0;
		}
	}
	ft_printf("printed done, ants: %i\n", lemin->ants);
	place_ants(lemin);
	ft_printf("PLACED ALL ANTS, WHOOOOOOHOOOO\n");
	if (file)
		ft_free_rstr(file);
	if (lemin)
		ft_free_lemin(lemin);
	//ft_printf("STRUCT SIZE %d", sizeof(t_rstr));
	// while (1)
	// 	continue;
	return (0);
}
