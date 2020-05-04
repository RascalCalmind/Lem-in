/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_store.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 14:01:47 by lhageman      #+#    #+#                 */
/*   Updated: 2020/05/04 14:57:57 by wmisiedjan    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

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

int			ft_store_room(t_lemin *lemin, t_rstr *file)
{
	char	**args;
	int		hash;
	t_room	*start;
	t_room	*room;
	int		ret;

	ret = 1;
	args = ft_room_check(file->str);

	ft_printf("TRYING TO STORE ROOM: %s\n", args[0]);
	if (args == NULL)
		return (ft_free_error(lemin, file, 3));
	hash = ft_hash_sdbm(args[0], MAX_HASHTABLE);
	start = lemin->room[hash];
	room = (t_room *)ft_memalloc(sizeof(t_room));
	room->name = ft_strdup(args[0]);
	room->x = ft_atoi(args[1]);
	room->y = ft_atoi(args[2]);
	if (start == NULL){
		ft_printf("%s start null\n", room->name);
		start = room;
	}
	else{
		ft_printf("%s start not null\n", room->name);
		ret = ft_check_room(lemin->room[hash], room);
	}
	ft_free_char_arr(args, 4);
	if (ret != 1)
		return (ft_free_error(lemin, file, ret));
	lemin->room[hash] = start;
	return (1);
}
