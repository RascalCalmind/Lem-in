/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_store.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 14:01:47 by lhageman       #+#    #+#                */
/*   Updated: 2020/03/07 16:06:32 by lhageman      ########   odam.nl         */
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
	if (list->room[end] != NULL)
	{
		temp = list->room[end];
		while (list->room[end] != NULL &&\
				ft_strcmp(list->room[end]->name, str) != 0 &&\
				list->room[end]->next)
			list->room[end] = list->room[end]->next;
		if (list->room[end] && ft_strcmp(list->room[end]->name, str) != 0)
		{
			list->room[end] = temp;
			return (-1);
		}
		else
		{
			x = (room->x / 1.0) - (list->room[end]->x / 1.0);
			y = (room->y / 1.0) - (list->room[end]->y / 1.0);
			y *= y;
			h = x + y;
			h = ft_sqrt(h);
		}
		list->room[end] = temp;
	}
	return (h);
}

int			ft_store_room(t_lemin *lemin, t_rstr *file)
{
	char	**args;
	int		i;
	int		hash;
	int		ret;
	t_room	*temp;
	t_room	*p;
	t_room	*room;

	i = 0;
	ret = 0;
	args = ft_room_check(file->str);
	if (args == NULL)
		return (ft_free_error_lem_rstr(lemin, file));
	hash = ft_hash_sdbm(args[0], MAX_HASHTABLE);
	room = (t_room *)ft_memalloc(sizeof(t_room));
	if (lemin->room[hash] != NULL)
	{
		temp = lemin->room[hash];
		while (lemin->room[hash]->next != NULL)
			lemin->room[hash] = lemin->room[hash]->next;
		lemin->room[hash]->next = room;
		lemin->room[hash] = lemin->room[hash]->next;
	}
	else
	{
		lemin->room[hash] = room;
		temp = lemin->room[hash];
	}
	lemin->room[hash]->name = ft_strdup(args[0]);
	lemin->room[hash]->x = ft_atoi(args[1]);
	lemin->room[hash]->y = ft_atoi(args[2]);
	ft_free_char_arr(args, 4);
	p = lemin->room[hash];
	lemin->room[hash] = temp;
	if (lemin->end != NULL)
		p->h = ft_calc_heuridian(lemin, p, lemin->end);
	return (1);
}
