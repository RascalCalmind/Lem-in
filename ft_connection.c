/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_connection.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 13:00:40 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/26 18:45:43 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int		ft_in_lemin(char *str, t_lemin *list)
{
	int		index;
	t_room	*temp;

	index = 0;
	if (!str || !list)
		return (-1);
	index = ft_hash_sdbm(str, MAX_HASHTABLE);
	temp = list->room[index];
	while (list->room[index])
	{
		if (ft_strcmp(list->room[index]->name, str) == 0)
		{
			list->room[index] = temp;
			return (0);
		}
		list->room[index] = list->room[index]->next;
	}
	list->room[index] = temp;
	return (-1);
}

t_room	*ft_pointer_room(char *str, int index, t_lemin *list, t_room *pointer)
{
	t_room *temp;

	temp = list->room[index];
	while (list->room[index])
	{
		if (ft_strcmp(list->room[index]->name, str) == 0)
		{
			pointer = list->room[index];
			list->room[index] = temp;
			return (pointer);
		}
		list->room[index] = list->room[index]->next;
	}
	list->room[index] = temp;
	return (NULL);
}

int		ft_assign_connection(char **arr, t_lemin *list)
{
	t_room	*from;
	t_room	*to;
	// t_room	*temp;
	int		from_index;
	int		to_index;
	int		i;

	i = 0;
	from = NULL;
	to = NULL;
	//ft_printf("---Assigning connections---\n");
	from_index = ft_hash_sdbm(arr[0], MAX_HASHTABLE);
	to_index = ft_hash_sdbm(arr[1], MAX_HASHTABLE);
	//ft_printf("-calculated indexes-\n");
	from = ft_pointer_room(arr[0], from_index, list, from); // FROM
	to = ft_pointer_room(arr[1], to_index, list, to); // TO
//	ft_printf("-created pointers to rooms-\n");
	if (from->edges == NULL)
		from->edges = (t_edge **)ft_memalloc(sizeof(t_edge *) * (list->rooms + 1));
	ft_printf("FT_ASS_CONN --- allocated edges for to \n");
	from_index = 0;
	while (from->edges[from_index] != NULL)
		from_index += 1;
	ft_printf("FT_ASS_CONN --- i to assign: %i\n", from_index);
	from->edges[from_index] = (t_edge *)ft_memalloc(sizeof(t_edge));
	//a->edges[i]->to = (t_room *)ft_memalloc(sizeof(t_room *));
	from->edges[from_index]->to = to;
	from->edges[from_index]->available = 1;
	from->link_count = from_index + 1;

	to_index = 0;
	if (to->edges == NULL)
		to->edges = (t_edge **)ft_memalloc(sizeof(t_edge *) * (list->rooms + 1));
	ft_printf("FT_ASS_CONN --- allocated edges for from\n");
	while (to->edges[to_index] != NULL)
		to_index += 1;
	to->edges[to_index] = (t_edge *)ft_memalloc(sizeof(t_edge));
	//b->edges[i]->to = (t_room *)ft_memalloc(sizeof(t_room *));
	to->edges[to_index]->to = from;
	to->edges[to_index]->available = 1;
	to->link_count = to_index + 1;
	from->edges[from_index]->rev = to->link_count;
	to->edges[to_index]->rev = from->link_count - 1;
	ft_printf("-assigned pointers to links-\n---\n");
	return (0);
}

int		ft_connection(char *str, t_lemin *list)
{
	int		i;
	char	**arr;

	//ft_printf("MAKING CONNECTIONS with %s\t\t\n", str);
	i = 0;
	if (!str)
		return (-1);
	if (ft_contains(str, '-') == 1)
	{
		//ft_printf("Correct amount of '-' characters\n");
		arr = ft_strsplit(str, '-');
		if (!arr)
			return (-1);
		if (ft_in_lemin(arr[0], list) < 0 || ft_in_lemin(arr[1], list) < 0)
		{
			ft_free_char_arr(arr, 2);
			return (-1);
		}
		else
		{
			//ft_printf("Rooms both exist in database\n");
			if (ft_assign_connection(arr, list) == 0)
			{
				ft_free_char_arr(arr, 2);
				//ft_printf("CONNECTIONS ASSIGNED \t\t\n---\n");
				return (0);
			}
			ft_free_char_arr(arr, 2);
			return (-1);
		}
	}
	else
		return (-1);
}
