/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bfs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:14:06 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/28 16:49:24 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lem_in.h"

static void	reset_levels(t_room *room)
{
	if (room != NULL)
	{
		room->level = -1;
	}
}

static void	reset_visit(t_room *room, t_path **paths, int cpath)
{
	int p;
	int r;

	p = 0;
	r = 0;
	ft_printf("RESET VISIT ------\n");
	if (room->visited == 1)
	{
		while (p <= cpath)
		{
			while (r <= paths[p]->len)
			{
				if (paths[p]->room[r] == room)
				{
					if (r == 0)
						break;
					ft_printf("RESET_VISIT in path: %s\n", room->name);
					return ;
				}
				r += 1;
			}
			p += 1;
			r = 0;
		}
		ft_printf("RESET_VISIT for room: %s\n", room->name);
		room->visited = 0;
	}
	// while (1)
	// 	;
}

static void	ft_bfs_queueing(t_queue *queue)
{
	int		i;
	int		j;
	t_room	*room;

	i = 0;
	j = 0;
	room = ft_dequeue(queue);
	while (room != NULL)
	{
		ft_printf("FT_BFS-- CURRENT ROOM %s - visited %d - LEVEL %i\n", room->name, room->visited, room->level);
		while (room->edges && room->edges[i] != NULL)
		{
			ft_printf("FT_BFS--edges exist room: %s\n", room->edges[i]->to->name);
			ft_printf("ft inqueue return: %i\n", ft_inqueue(queue, room->edges[i]->to));
			ft_printf("visited = %i\n", room->edges[i]->to->visited);
			if (ft_inqueue(queue, room->edges[i]->to) == 1 &&
				room->edges[i]->to->visited == 0)
			{
				ft_printf("FT_ENQUEUEING ---- enqueueing path: %s\n", room->edges[i]->to->name);
				ft_enqueue(queue, room->edges[i]->to);
				queue->prev[j] = room->edges[i]->to;
				room->edges[i]->to->level = room->level + 1;
				j += 1;
			}
			i += 1;
		}
		i = 0;
		ft_printf("FT_dEQUEUEING ---- dequeueing path: %s\n", queue->list[0]->name);
		room = ft_dequeue(queue);
	}
}

int		ft_bfs(t_lemin *list, t_room *start, t_room *end)
{
	t_queue	*queue;

	queue = ft_queue(list->rooms);
	ft_room_map(list, reset_levels);
	start->level = 0;
	ft_printf("FT_BFS ---- Created queue queue\n");
	ft_printf("FT_BFS ---- Found startroom %s\n", start->name);
	ft_enqueue(queue, start);	
	if (list->path_count > 0)
		ft_room_map_v(list, reset_visit);
	ft_printf("FT_BFS ---- Enqueued endroom into queue\n");
	ft_bfs_queueing(queue);
	ft_printf("FT_BFS ---- Created queue\n");
	ft_print_arr_room(queue->prev);
	ft_free_queue(queue);
	start->level = 0;
	return (0);
}
