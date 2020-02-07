/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_store.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 14:01:47 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/07 21:04:12 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

double		ft_calc_heuridian(t_lemin *list, t_room *room, char *str)
{
	double	h;
	int		end;
	int		x;
	int		y;
	t_room	*temp;

	h = 0;
	end = ft_hash_sdbm(str, MAX_HASHTABLE);
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
		{
			list->room[end] = temp;
			return (-1);
		}
		else
		{
			x = room->x - list->room[end]->x;
			x *= x;
			y = room->y - list->room[end]->y;
			y *= y;
			h = x + y;
			//h = sqrt((room->x - list->room[end]->x)^2 + (room->y - list->room[end]->y)^2);
		}
		list->room[end] = temp;
	}
	ft_printf("heuridian: %i\n---\n", h);
	return (h);
}

int			ft_store_room(t_lemin *lemin, t_rstr *file)
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
		return (ft_free_error_lem_rstr(lemin, file));
	hash = ft_hash_sdbm(args[0], MAX_HASHTABLE);
	ft_printf("ft_store_room\t\thash: %i | NAME: %s\n", hash, args[0]);
	room = (t_room *)ft_memalloc(sizeof(t_room));
	if (lemin->room[hash] != NULL)
	{
		ft_printf("ft_store_room\t\t EXISTING ROOM STATUS TEMP: %s\n", lemin->room[hash]->name);
		temp = lemin->room[hash];
		ft_printf("ft_store_room\t\tsetting temp to first node\n");
		while (lemin->room[hash]->next != NULL)
		{
			ft_printf("ft_store_room LOOP:\t\tLooping to next room.....\n");
			lemin->room[hash] = lemin->room[hash]->next;
		}
		ft_printf("ft_store_room\t\t ASSIGNING ROOM INTO NEXT OF %s\n", lemin->room[hash]->name);
		lemin->room[hash]->next = room;
		ft_printf("ft_store_room\t\tsetting current node to new room\n");
		lemin->room[hash] = lemin->room[hash]->next;
	}
	else
	{
		ft_printf("ft_store_room\t\tgoing into null\n");
		lemin->room[hash] = room;
		ft_printf("ft_store_room\t\tassigned new room to lemin->room[hashnum]\n");
		temp = lemin->room[hash];
		ft_printf("ft_store_room\t\tset temp to current new room\n");
	}
	lemin->room[hash]->name = ft_strdup(args[0]);
	ft_printf("ft_store_room\t\tassigned name to room\n");
	lemin->room[hash]->x = ft_atoi(args[1]);
	ft_printf("ft_store_room\t\tassigned x to room\n");
	lemin->room[hash]->y = ft_atoi(args[2]);
	ft_printf("ft_store_room\t\tassigned y to room\n");
	ft_free_char_arr(args, 4);
	if (lemin->end != NULL)
		lemin->room[hash]->h = ft_calc_heuridian(lemin, lemin->room[hash], lemin->end);
	ft_printf("ft_store_room\t\tcalculated euclidian distance if possible\n---\n");
	lemin->room[hash] = temp;
	ft_printf("ft_store_room\t\tRESET STATUS TEMP: %s\n", lemin->room[hash]->name);
	ft_print_lemin(lemin);
	return (1);
}

// int		ft_create_lists(t_lemin *list, t_rstr *file)
// {
// 	list->room = 
// 	return (0);
// }
