/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_connection.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 13:00:40 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/22 14:33:13 by lhageman      ########   odam.nl         */
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
	t_room	*a;
	t_room	*b;
	// t_room	*temp;
	int		indexa;
	int		indexb;
	int		i;

	i = 0;
	a = NULL;
	b = NULL;
	//ft_printf("---Assigning connections---\n");
	indexa = ft_hash_sdbm(arr[0], MAX_HASHTABLE);
	indexb = ft_hash_sdbm(arr[1], MAX_HASHTABLE);
	//ft_printf("-calculated indexes-\n");
	a = ft_pointer_room(arr[0], indexa, list, a);
	b = ft_pointer_room(arr[1], indexb, list, b);
//	ft_printf("-created pointers to rooms-\n");
	// if (a->links[indexb] == NULL)
	// 	a->links[indexb] = b;
	// if (a->links[indexb] != NULL)
	// {
	// 	temp = a->links[indexb];
	// 	while ()
	// }
	// if (a->links == NULL)
	// 	a->links = (t_room **)ft_memalloc(sizeof(t_room *) * (list->rooms + 1));
	// while (a->links[i] != NULL)
	// 	i += 1;
	// a->links[i] = b;
	// a->link_count = i;
	// i = 0;
	// if (b->links == NULL)
	// 	b->links = (t_room **)ft_memalloc(sizeof(t_room *) * (list->rooms + 1));
	// while (b->links[i] != NULL)
	// 	i += 1;
	// b->links[i] = a;
	// b->link_count = i;
	if (a->edges == NULL)
		a->edges = (t_edge **)ft_memalloc(sizeof(t_edge *) * (list->rooms + 1));
	ft_printf("FT_ASS_CONN --- allocated edges for a \n");
	while (a->edges[i] != NULL)
		i += 1;
	ft_printf("FT_ASS_CONN --- i to assign: %i\n", i);
	a->edges[i] = (t_edge *)ft_memalloc(sizeof(t_edge *));
	//a->edges[i]->to = (t_room *)ft_memalloc(sizeof(t_room *));
	a->edges[i]->to = b;
	a->edges[i]->available = 1;
	a->link_count = i;
	i = 0;
	if (b->edges == NULL)
		b->edges = (t_edge **)ft_memalloc(sizeof(t_edge *) * (list->rooms + 1));
	ft_printf("FT_ASS_CONN --- allocated edges for b\n");
	while (b->edges[i] != NULL)
		i += 1;
	b->edges[i] = (t_edge *)ft_memalloc(sizeof(t_edge *));
	//b->edges[i]->to = (t_room *)ft_memalloc(sizeof(t_room *));
	b->edges[i]->to = a;
	b->edges[i]->available = 1;
	b->link_count = i;
	//ft_printf("-assigned pointers to links-\n---\n");
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
