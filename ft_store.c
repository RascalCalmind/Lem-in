/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_store.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 14:01:47 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/19 10:08:40 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

double		ft_calc_heuridian(t_lemin *list, t_room *room, char *str)
{
	double	h;
	int		end;
	double	x;
	double	y;
	t_room	*temp;

	h = 0;
	end = ft_hash_sdbm(str, MAX_HASHTABLE);
	x = 0;
	y = 0;
	//ft_printf("ft_calc_heuridian\tcalculating heuridian, end int: [%i] for [%s]\n", end, str);
	if (list->room[end] != NULL)
	{
		temp = list->room[end];
		while (list->room[end] != NULL && ft_strcmp(list->room[end]->name, str) != 0 &&
			list->room[end]->next)
		{
			//ft_printf("list->room[end]->str = %s\n", list->room[end]->name);	
			list->room[end] = list->room[end]->next;
		}
		if (list->room[end] && ft_strcmp(list->room[end]->name, str) != 0)
		{
			//ft_printf("Heuridian, couldn't find room to store heuridian [%s][%s]\n", list->room[end]->name, str);
			list->room[end] = temp;
			return (-1);
		}
		else
		{
			//ft_printf("%i, %i, %i, %i\n", room->x, list->room[end]->x, room->y, list->room[end]->y);
			x = (room->x / 1.0) - (list->room[end]->x / 1.0);
			//ft_printf("HEURIDIAN x: %f\n", x);
			x *= x;
			//ft_printf("HEURIDIAN x: %f\n", x);
			y = (room->y / 1.0) - (list->room[end]->y / 1.0);
			//ft_printf("HEURIDIAN y: %f\n", y);
			y *= y;
			//ft_printf("HEURIDIAN y: %f\n", y);
			h = x + y;
			//ft_printf("HEURIDIANNNN h: %f + %f = %f\n", x, y, h);
			h = ft_sqrt(h);
			//ft_printf("lets see if this sqrt works: %f\n", h);
			//h = sqrt((room->x - list->room[end]->x)^2 + (room->y - list->room[end]->y)^2);
		}
		list->room[end] = temp;
	}
	// else
	// {
	// 	//ft_printf("heuridian end does not exist\n");
	// 	if (list->room[end] != NULL)
	// 		//ft_printf("endroom is null\n");
	// 	if (ft_strcmp(list->room[end]->name, str) != 0)
	// 	//	ft_printf("name is not equal to str\n");
	// 	if (list->room[end]->next != NULL)
	// 		//ft_printf("next is not equal to null\n");
	// }
	//ft_printf("heuridian: %f\n---\n", h);
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
	//ft_printf("ft_store_room\t\thash: %i | NAME: %s\n", hash, args[0]);
	room = (t_room *)ft_memalloc(sizeof(t_room));
	if (lemin->room[hash] != NULL)
	{
		//ft_printf("ft_store_room\t\t EXISTING ROOM STATUS TEMP: %s\n", lemin->room[hash]->name);
		temp = lemin->room[hash];
	//	ft_printf("ft_store_room\t\tsetting temp to first node\n");
		while (lemin->room[hash]->next != NULL)
		{
			//ft_printf("ft_store_room LOOP:\t\tLooping to next room.....\n");
			lemin->room[hash] = lemin->room[hash]->next;
		}
		//ft_printf("ft_store_room\t\t ASSIGNING ROOM INTO NEXT OF %s\n", lemin->room[hash]->name);
		lemin->room[hash]->next = room;
		//ft_printf("ft_store_room\t\tsetting current node to new room\n");
		lemin->room[hash] = lemin->room[hash]->next;
	}
	else
	{
		//ft_printf("ft_store_room\t\tgoing into null\n");
		lemin->room[hash] = room;
	//	ft_printf("ft_store_room\t\tassigned new room to lemin->room[hashnum]\n");
		temp = lemin->room[hash];
		//ft_printf("ft_store_room\t\tset temp to current new room\n");
	}
	lemin->room[hash]->name = ft_strdup(args[0]);
//	ft_printf("ft_store_room\t\tassigned name to room\n");
	lemin->room[hash]->x = ft_atoi(args[1]);
//	ft_printf("ft_store_room\t\tassigned x to room\n");
	lemin->room[hash]->y = ft_atoi(args[2]);
//	ft_printf("ft_store_room\t\tassigned y to room\n");
	ft_free_char_arr(args, 4);	
	lemin->room[hash] = temp;
	if (lemin->end != NULL)
		lemin->room[hash]->h = ft_calc_heuridian(lemin, lemin->room[hash], lemin->end);
//	ft_printf("ft_store_room\t\tcalculated Heuridian distance if possible\n---\n");

//	ft_printf("ft_store_room\t\tRESET STATUS TEMP: %s\n", lemin->room[hash]->name);
//	ft_print_lemin(lemin);
	return (1);
}

// int		ft_create_lists(t_lemin *list, t_rstr *file)
// {
// 	list->room = 
// 	return (0);
// }
