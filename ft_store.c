/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_store.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 14:01:47 by lhageman      #+#    #+#                 */
/*   Updated: 2020/05/15 16:29:12 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static char	**ft_room_str(char *str)
{
	char	**arr;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	arr = ft_strsplit(str, ' ');
	while (i < 3)
	{
		if (i > 0)
		{
			ret = ft_check_int(arr[i]);
			if (ret != 0)
				return (NULL);
		}
		i += 1;
	}
	return (arr);
}

static int	ft_check_room(t_room *start, t_room *room)
{
	t_room *current;

	current = start;
	while (current->next)
	{
		if (ft_strcmp(current->name, room->name) == 0)
		{
			ft_free_room(room);
			return (ERR_DOUBLE_ROOM);
		}
		current = current->next;
	}
	if (ft_strcmp(current->name, room->name) == 0)
	{
		ft_free_room(room);
		return (ERR_DOUBLE_ROOM);
	}
	current->next = room;
	return (1);
}

int			ft_store_room(t_lemin *lemin)
{
	char	**args;
	int		hash;
	t_room	*start;
	t_room	*room;
	int		ret;

	ret = 1;
	args = ft_room_str(lemin->line->str);
	if (args == NULL)
		return (ft_free_error(lemin, 3));
	hash = ft_hash_sdbm(args[0], MAX_HASHTABLE);
	start = lemin->room[hash];
	room = (t_room *)ft_memalloc(sizeof(t_room));
	room->name = ft_strdup(args[0]);
	room->x = ft_atoi(args[1]);
	room->y = ft_atoi(args[2]);
	if (start == NULL)
		start = room;
	else
		ret = ft_check_room(lemin->room[hash], room);
	ft_free_char_arr(args, 4);
	if (ret != 1)
		return (ft_free_error(lemin, ret));
	lemin->room[hash] = start;
	return (1);
}
