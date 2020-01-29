/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lem_in.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:34:10 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/29 15:55:01 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int		ft_create_lists(t_lemin *list, char **arr)
{
	int i;

	i = 0;
	while (i < 355)
	{
		
		i += 1;
	}
	return (0);
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
			}
			else if (ft_strlen(file->str) > 1 && file->str[0] == '#'
				&& file->str[1] == '#')
			{
				if (ft_strcmp(file->str, "##start") != 0 &&
					ft_strcmp(file->str, "##end") != 0)
				{
					free(file->str);
				}
			}
			if (file->str != NULL)
			{
				file->next = malloc(sizeof(t_rstr));
				file = file->next;
			}
		}
	}
	return (0);
}

// int	ft_read(char **arr)
// {
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	while (get_next_line(STDIN_FILENO, &line) && i < 15000)
// 	{
// 		if (ft_strlen(line) > 0)
// 		{
// 			arr[i] = malloc(sizeof(char *) * ft_strlen(line));
// 			arr[i] = ft_strdup(line);
// 			i += 1;
// 			if (ft_strlen(arr[i - 1]) > 1 && arr[i - 1][0] == '#'
// 				&& arr[i - 1][1] != '#')
// 			{
// 				free(arr[i - 1]);
// 				i -= 1;
// 			}
// 			else if (ft_strlen(arr[i - 1]) > 1 && arr[i - 1][0] == '#'
// 				&& arr[i - 1][1] == '#')
// 			{
// 				if (ft_strcmp(arr[i - 1], "##start") != 0 &&
// 					ft_strcmp(arr[i - 1], "##end") != 0)
// 				{
// 					free(arr[i - 1]);
// 					i -= 1;
// 				}
// 			}
// 		}
// 	}
// 	return (i);
// }

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
	if (ret < 1)
		return (ft_error(4));
	// while (j < ret)
	// {
	// 	ft_printf("%s\n", arr[j]);
	// 	j += 1;
	// }
	// ret = ft_create_lemin(list);
	// if (list == NULL || ret == -1)
	// {
	// 	ft_free_char_array(arr, 15000);
	// 	return (ft_error(3));
	// }
	// ft_create_lists(list, arr);
	free(arr);
}

// int	main(int argc, char **argv)
// {
// 	int		ret;
// 	char	**arr;
// 	int		j;
// 	t_lemin *list;

// 	j = 0;
// 	argv[0] = NULL;
// 	arr = malloc(sizeof(char **) * 15000);
// 	if (!arr)
// 		return (ft_error(3));
// 	if (argc > 1)
// 		return (ft_error(1));
// 	ret = ft_read(arr);
// 	if (ret < 1)
// 		return (ft_error(4));
// 	while (j < ret)
// 	{
// 		ft_printf("%s\n", arr[j]);
// 		j += 1;
// 	}
// 	// ret = ft_create_lemin(list);
// 	// if (list == NULL || ret == -1)
// 	// {
// 	// 	ft_free_char_array(arr, 15000);
// 	// 	return (ft_error(3));
// 	// }
// 	// ft_create_lists(list, arr);
// 	free(arr);
// }
