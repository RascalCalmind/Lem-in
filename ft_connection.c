/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_connection.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 13:00:40 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/07 16:00:47 by lhageman      ########   odam.nl         */
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
	index = ft_hash_sdbm(str, list->rooms);
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
		if (ft_strcmp(list->room[index]->name, str)== 0)
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
	ft_printf("---Assigning connections---\n");
	indexa = ft_hash_sdbm(arr[0], list->rooms);
	indexb = ft_hash_sdbm(arr[1], list->rooms);
	ft_printf("-calculated indexes-\n");
	a = ft_pointer_room(arr[0], indexa, list, a);
	b = ft_pointer_room(arr[1], indexb, list, b);
	ft_printf("-created pointers to rooms-\n");
	// if (a->links[indexb] == NULL)
	// 	a->links[indexb] = b;
	// if (a->links[indexb] != NULL)
	// {
	// 	temp = a->links[indexb];
	// 	while ()
	// }
	if (a->links == NULL)
		a->links = ft_memalloc(sizeof(t_room **) * list->rooms);
	while (a->links[i] != NULL)
		i += 1;
	a->links[i] = b;
	i = 0;
	if (b->links == NULL)
		b->links = ft_memalloc(sizeof(t_room **) * list->rooms);
	while (b->links[i] != NULL)
		i += 1;
	b->links[i] = a;
	ft_printf("-assigned pointers to links-\n---\n");
	return (0);
}

int		ft_connection(char *str, t_lemin *list)
{
	int		i;
	char	**arr;

	ft_printf("MAKING CONNECTIONS with %s\t\t\n", str);
	i = 0;
	if (!str)
		return (-1);
	if (ft_contains(str, '-') == 1)
	{
		ft_printf("Correct amount of '-' characters\n");
		arr = ft_strsplit(str, '-');
		if (!arr)
			return (-1);
		if (ft_in_lemin(arr[0], list) < 0 || ft_in_lemin(arr[1], list) < 0)
		{
			free(arr);
			return (-1);
		}
		else
		{
			ft_printf("Rooms both exist in database\n");
			if (ft_assign_connection(arr, list) == 0)
			{
				free(arr);
				ft_printf("CONNECTIONS ASSIGNED \t\t\n---\n");
				return (0);
			}
			free(arr);
			return (-1);
		}
	}
	else
		return (-1);
}
