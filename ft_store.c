/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_store.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 14:01:47 by lhageman      #+#    #+#                 */
/*   Updated: 2020/04/20 16:28:07 by wmisiedjan    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int			ft_store_room(t_lemin *lemin, t_rstr *file)
{
	char	**args;
	int		hash;
	t_room	*start;
	t_room	*room;

	args = ft_room_check(file->str);
	if (args == NULL)
		return (ERR_PARSE_ROOM);
	hash = ft_hash_sdbm(args[0], MAX_HASHTABLE);
	start = lemin->room[hash];
	room = (t_room *)ft_memalloc(sizeof(t_room));
	room->name = ft_strdup(args[0]);
	room->x = ft_atoi(args[1]);
	room->y = ft_atoi(args[2]);
	if (start == NULL)
		start = room;
	else
	{
		while (lemin->room[hash]->next != NULL)
			lemin->room[hash] = lemin->room[hash]->next;
		lemin->room[hash]->next = room;
	}
	ft_free_char_arr(args, 4);
	lemin->room[hash] = start;
	return (1);
}
