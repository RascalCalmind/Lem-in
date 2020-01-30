/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lem_in.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:34:10 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/30 15:52:47 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int		ft_free_error_lem_rstr(t_lemin *list, t_rstr *file)
{
	ft_free_rstr(file);
	ft_free_lemin(list);
	return (-1);
}

int		ft_create_lists(t_lemin *list, t_rstr *file)
{
	int start;
	int end;
	int ret;
	char **arr;

	start = 0;
	end = 0;
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
		if (ft_strcmp(file->str, "##start") == 0 && start == 0)
		{
			file = file->next;
			if (!file->str)
				return (ft_free_error_lem_rstr(list, file));
			arr = ft_room_check(file->str);
			if (arr == NULL)
				return (ft_free_error_lem_rstr(list, file));
			list->start = arr[0];
			free(arr);
			ft_store_room(list, file);
			start = 1;
		}
		else if (ft_strcmp(file->str, "##end") == 0 && end == 0)
		{
			file = file->next;
			if (!file->str)
				return (ft_free_error_lem_rstr(list, file));
			arr = ft_room_check(file->str);
			if (arr == NULL)
				return (ft_free_error_lem_rstr(list, file));
			list->end = arr[0];
			free(arr);
			ft_store_room(list, file);
			end = 1;
		}
		else if (ft_contains(file->str, ' ') == 2)
			ret = ft_store_room(list, file);
		if (ret == -1)
			return (-1);
		// else
		// 	ft_store_connexion(list, file);
		file = file->next;
	}
	return (0);
}

int	ft_read(t_rstr *file)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(STDIN_FILENO, &line))
	{
		if (ft_strlen(line) > 0)
		{
			file->str = malloc(sizeof(char *) * ft_strlen(line));
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
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		ret;
	int		j;
	t_rstr	*file;
	t_lemin *list;

	j = 0;
	argv[0] = NULL;
	file = malloc(sizeof(t_rstr));
	if (!file)
		return (ft_error(3));
	if (argc > 1)
		return (ft_error(1));
	file->str = NULL;
	file->next = NULL;
	ret = ft_read(file);
	list = malloc(sizeof(t_lemin));
	if (!list)
	{
		ft_free_rstr(file);
		return (ft_error(3));
	}
	ret = ft_create_lemin(list);
	if (list == NULL || ret == -1)
	{
		ft_free_rstr(file);
		return (ft_error(3));
	}
	ret = ft_create_lists(list, file);
	if (ret == -1)
		return (ft_error(4));
	ft_printf("start: %s, end: %s, ants: %i\n", list->start, list->end, list->ants);
	ft_free_rstr(file);
	ft_free_lemin(list);
}
