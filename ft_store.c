/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_store.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 14:01:47 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/06 16:10:21 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int		ft_calc_heuridian(t_lemin *list, t_room *room, char *str)
{
	int h;
	int end;
	int x;
	int y;
	t_room *temp;

	h = 0;
	end = ft_hash_sdbm(str, 8);
	x = 0;
	y = 0;
	ft_printf("ft_calc_heuridian\tcalculating heuridian\n");
	if (list->room[end] != NULL && list->room[end]->name != str &&
		list->room[end]->next != NULL)
	{
		temp = list->room[end];
		while (list->room[end] != NULL && list->room[end]->name != str &&
			list->room[end]->next)
			list->room[end] = list->room[end]->next;
		if (list->room[end] && list->room[end]->name != str)
			return (-1);
		else
		{
			x = room->x - list->room[end]->x;
			x *= x;
			y = room->y - list->room[end]->y;
			y *= y;
			h = x + y;
			//h = sqrt((room->x - list->room[end]->x)^2 + (room->y - list->room[end]->y)^2);
		}
	}
	ft_printf("heuridian: %i\n---\n", h);
	return (h);
}

int		ft_store_room(t_lemin *list, t_rstr *file)
{
	char	**args;
	int		i;
	int		hash;
	int		ret;
	t_room	*temp;
	t_room	*room;

	i = 0;
	ret = 0;
	args = ft_room_check(file->str);
	if (args == NULL)
		return (ft_free_error_lem_rstr(list, file));
	hash = ft_hash_sdbm(args[0], 8);
	ft_printf("ft_store_room\t\thash: %i\n", hash);
	if (list->room[hash] != NULL)
	{
		ft_printf("ft_store_room\t\tgoing into not null\n");
		temp = list->room[hash];
		ft_printf("ft_store_room\t\tsetting temp to first node\n");
		while (list->room[hash]->next != NULL)
			list->room[hash] = list->room[hash]->next;
		ft_printf("ft_store_room\t\tlooping to find the last node\n");
		room = malloc(sizeof(t_room));
		ft_printf("ft_store_room\t\tallocating new room\n");
		list->room[hash]->next = room;
		ft_printf("ft_store_room\t\tsetting next node to new room\n");
		list->room[hash] = list->room[hash]->next;
	}
	else
	{
		ft_printf("ft_store_room\t\tgoing into null\n");
		room = malloc(sizeof(t_room));
		list->room[hash] = room;
		ft_printf("ft_store_room\t\tassigned new room to list->room[hashnum]\n");
		temp = list->room[hash];
		ft_printf("ft_store_room\t\tset temp to current new room\n");
	}
	ret = ft_create_room(list->room[hash]);
	ft_printf("ft_store_room\t\tset all variables of new room\n");
	if (ret == -1)
		return (ft_free_error_lem_rstr(list, file));
	list->room[hash]->name = ft_strdup(args[0]);
	ft_printf("ft_store_room\t\tassigned name to room\n");
	list->room[hash]->x = ft_atoi(args[1]);
	ft_printf("ft_store_room\t\tassigned x to room\n");
	list->room[hash]->y = ft_atoi(args[2]);
	ft_printf("ft_store_room\t\tassigned y to room\n");
	ft_free_char_arr(args, 4);
	if (list->end != NULL)
		list->room[hash]->h = ft_calc_heuridian(list, list->room[hash], list->end);
	ft_printf("ft_store_room\t\tcalculated euclidian distance if possible\n---\n");
	list->room[hash] = temp;
	return (1);
}

// int		ft_create_lists(t_lemin *list, t_rstr *file)
// {
// 	list->room = 
// 	return (0);
// }
