/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_lem.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 13:09:54 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/19 13:23:46 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int			ft_free_char_arr(char **arr, int len)
{
	int i;

	i = 0;
	//ft_printf("---\n");
	while (i < len)
	{
		if (arr[i])
		{
			//ft_printf("ft_free_char_array\t\tfree string in array %s\n", arr[i]);
			free(arr[i]);
			arr[i] = NULL;
		}
		i += 1;
	}
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
	//ft_printf("---\n");
	return (0);
}

int			ft_room_array_len(t_room **room)
{
	int i;

	i = 0;
	if (!room)
		return (0);
	while (room[i])
	{
		i += 1;
	}
	//ft_printf("room_array_len\t\t%i\n", i);
	return (i);
}

void		ft_free_room(t_room *room)
{
	unsigned int	i;

	i = 0;
	//ft_printf("-ft_free_room\t\t start\n");
	// ft_printf("coordinates\t\t\t%i,%i\n", room->x, room->y);
	if (room == NULL)
		return ;
	if (room->name != NULL)
	{
		//ft_printf("ft_free_room\t\tfree'ing room->name\n");
		free(room->name);
		room->name = NULL;
	}
	if (room->links != NULL)
	{
		free(room->links);
		room->links = NULL;
	}
	if (room->next != NULL)
	{
		//ft_printf("freeing next->rooms\n");
		ft_free_room(room->next);
	}
//	ft_printf("freeing room\n");
	free(room);
	room = NULL;
	//ft_printf("-ft_free_room\t\t the end\n---\n");
}

void		ft_free_lemin(t_lemin *list)
{
	unsigned int i;

	i = 0;
	//ft_printf("ft_free_lemin\t\tstart\n");
	if (list == NULL)
		return ;
	if (list->start != NULL)
	{
		//ft_printf("ft_free_lemin\t\tfree list->start\n");
		free(list->start);
		list->start = NULL;
	}
	if (list->end != NULL)
	{
		//ft_printf("ft_free_lemin\t\tfree list->end\n");
		free(list->end);
		list->end = NULL;
	}
	while (i < MAX_HASHTABLE)
	{
		if (list->room[i] != NULL)
		{
			//ft_printf("ft_free_lemin\t\tfree list->room %s\n", list->room[i]->name);
			ft_free_room(list->room[i]);
			list->room[i] = NULL;
			// free(list->room[i]);
			// list->room[i] = NULL;
		}
		i++;
	}
	if (list != NULL)
	{
		//ft_printf("ft_free_lemin\t\tfree list\n");
		free(list);
		list = NULL;
	}
//	ft_printf("ft_free_lemin\t\tthe end\n---\n");
}

void		ft_free_rstr(t_rstr *list)
{
	t_rstr *temp;

	//ft_printf("ft_free_rstr\t\t start\n");
	if (!list)
		return ;
	while (list->next != NULL)
	{
		temp = list->next;
		if (list)
		{
			if (list->str)
			{
				//ft_printf("\n--\nlist->str to be free'd: %s\n", list->str);
				free(list->str);
				list->str = NULL;
				//ft_printf("list->str free'd: %s\n--\n", list->str);
			}
			free(list);
			list = NULL;
		}
		list = temp;
	}
	if (list)
	{
		if (list->str)
		{
			//ft_printf("\n--\nlist->str to be free'd: %s\n--\n", list->str);
			free(list->str);
			list->str = NULL;
			//ft_printf("\n--\nlist->str free'd: %s\n--\n", list->str);
		}
		free(list);
		list = NULL;
	}
}
