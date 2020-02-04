/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lem_in.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:34:10 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/04 21:02:36 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int		ft_free_error_lem_rstr(t_lemin *list, t_rstr *file)
{
	ft_free_rstr(file);
	ft_free_lemin(list);
	return (-1);
}

// TODO: Handle errors for already existing start / end room.

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
		return (ft_store_room(list, file));
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
		ft_printf("ft_create_lists\t\tfile->str:%s\n", file->str);
		if (ft_strncmp(file->str, "##", 2) == 0)
		{
			if (ft_handle_command_line(list, file) == -1)
				return (-1);
		}
		else if (ft_contains(file->str, ' ') == 2)
		{
			if (!ft_store_room(list, file))
				return (-1);
		}
		// else
		// 	ft_store_connexion(list, file);
		file = file->next;
	}
	return (1);
}

 // Performance: maybe add ft_strnlen to not loop through entire string.
 
int	ft_read(t_rstr *file)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(STDIN_FILENO, &line))
	{
		if (ft_strlen(line) > 0)
		{
			file->str = ft_strdup(line);
			if (ft_strlen(file->str) > 1 && file->str[0] == '#'
				&& file->str[1] != '#')
			{
				free(file->str);
				file->str = NULL;
			}
			else if (ft_strlen(file->str) > 1 && file->str[0] == '#'
				&& file->str[1] == '#')
			{
				if (ft_strcmp(file->str, "##start") != 0 &&
					ft_strcmp(file->str, "##end") != 0)
				{
					free(file->str);
					file->str = NULL;
				}
			}
			if (file->str != NULL)
			{
				file->next = malloc(sizeof(t_rstr));
				file = file->next;
				file->str = NULL;
				file->next = NULL;
			}
		}
		free(line);
		line = NULL;
	}
	return (0);
}

int	ft_room_count(t_rstr *file)
{
	int		cnt;
	char	**arr;

	cnt = 0;
	while (file->next != NULL)
	{
		if (file->str && ft_contains(file->str, ' ') == 2)
		{
			arr = ft_strsplit(file->str, ' ');
			if (ft_check_int(arr[1]) == 0 && ft_check_int(arr[2]) == 0)
				cnt += 1;
			if (arr)
				ft_free_char_arr(arr, 4);
		}
		file = file->next;
	}
	if (file->str && ft_contains(file->str, ' ') == 2)
	{
		arr = ft_strsplit(file->str, ' ');
		if (ft_check_int(arr[1]) == 0 && ft_check_int(arr[2]) == 0)
			cnt += 1;
		if (arr)
			ft_free_char_arr(arr, 4);
	}
	return (cnt);
}

int	main(int argc, char **argv)
{
	int		ret;
	int		j;
	t_rstr	*file;
	t_lemin *list;

	j = 0;
	argv[0] = NULL;
	file = ft_memalloc(sizeof(t_rstr));
	if (!file)
		return (ft_error(ERR_MEM));
	if (argc > 1)
		return (ft_error(ERR_PARAMS));
	ret = ft_read(file);
	list = ft_memalloc(sizeof(t_lemin));
	if (!list)
	{
		ft_free_rstr(file);
		return (ft_error(ERR_MEM));
	}
	ret = ft_room_count(file);
	if (ret < 2)
	{
		free(list);
		list = NULL;
		ft_free_rstr(file);
		return (ft_error(ERR_PARAMS));
	}
	ret = ft_create_lemin(list, ret);
	if (list == NULL || ret == -1)
	{
		ft_free_rstr(file);
		return (ft_error(3));
	}
	ret = ft_create_lists(list, file);
	if (ret == -1)
		return (ft_error(4));
	ft_printf("start: %s, end: %s, ants: %i\n", list->start, list->end, list->ants);
	ft_print_lemin(list);
	ft_free_rstr(file);
	ft_free_lemin(list);

	while (1)
		;
	return (0);
}
