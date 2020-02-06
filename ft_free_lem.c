/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_lem.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 13:09:54 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/06 14:29:42 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int			ft_free_char_arr(char **arr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (arr[i])
		{
			ft_printf("ft_free_char_array\t\tfree string in array %s\n---\n", arr[i]);
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
	ft_printf("room_array_len\t\t%i\n", i);
	return (i);
}

void		ft_free_room(t_room *room, unsigned int rooms)
{
	unsigned int	i;
	t_room			*temp;

	i = 0;
	ft_printf("ft_free_room\t\t start\n");
	temp = NULL;
	if (room == NULL)
		return ;
	if (room->name != NULL)
	{
		ft_printf("ft_free_room\t\tfree'ing room->name [%s]\n", room->name);
		free(room->name);
		room->name = NULL;
	}
	if (room->links != NULL)
	{
		ft_printf("ft_free_room\t\tfree'ing room->links\n");
		free(room->links);
		room->links = NULL;
	}
	if (room->next != NULL)
		ft_free_room(room->next, ft_room_array_len(&room->next));
	if (room != NULL)
	{
		free(room);
		room = NULL;
	}
	ft_printf("ft_free_room\t\t the end\n---\n");
}

void		ft_free_lemin(t_lemin *list)
{
	unsigned int i;

	i = 0;
	ft_printf("ft_free_lemin\t\tstart\n");
	if (!list)
		return ;
	if (list->start)
	{
		ft_printf("ft_free_lemin\t\tfree list->start\n");
		free(list->start);
		list->start = NULL;
	}
	if (list->end)
	{
		ft_printf("ft_free_lemin\t\tfree list->end\n");
		free(list->end);
		list->end = NULL;
	}
	while (i < list->rooms)
	{
		if (list->room[i] != NULL)
		{
			ft_printf("ft_free_lemin\t\tfree list->room\n");
			ft_free_room(list->room[i], list->rooms);
			// free(list->room[i]);
			// list->room[i] = NULL;
		}
		i++;
	}
	if (list->room) {
		free(list->room);
		list->room = NULL;
	}
	if (list)
	{
		ft_printf("ft_free_lemin\t\tfree list\n");
		free(list);
		list = NULL;
	}
	ft_printf("ft_free_lemin\t\tthe end\n---\n");
}

// void	ft_free_rstr(t_rstr *list)
// {
// 	t_rstr *temp;

// 	ft_printf("ft_free_rstr\t\t start\n");
// 	if (!list)
// 		return ;
// 	while (list->next != NULL)
// 	{
// 		temp = list->next;
// 		if (list->str)
// 		{
// 			ft_printf("ft_free_rstr\t\t free str %s\n", list->str);			
// 			free(list->str);
// 			list->str = NULL;
// 		}
// 		list = temp;
// 	}
// 	if (list)
// 	{
// 		ft_printf("ft_free_rstr\t\t free list\n");	
// 		free(list);
// 		list = NULL;
// 	}
// 	ft_printf("ft_free_rstr\t\t the end\n---\n");
// }

void	ft_free_rstr(t_rstr *list)
{
	t_rstr *temp;

	ft_printf("ft_free_rstr\t\t start\n");
	if (!list)
		return ;
	while (list->next != NULL)
	{
		temp = list->next;
		if (list)
		{
			if (list->str)
			{
				ft_printf("\n--\nlist->str to be free'd: %s\n", list->str);
				free(list->str);
				list->str = NULL;
				ft_printf("list->str free'd: %s\n--\n", list->str);
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
			ft_printf("\n--\nlist->str to be free'd: %s\n--\n", list->str);
			free(list->str);
			list->str = NULL;
			ft_printf("\n--\nlist->str free'd: %s\n--\n", list->str);
		}
		free(list);
		list = NULL;
	}
}
