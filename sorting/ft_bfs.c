/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bfs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:14:06 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/22 19:49:08 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lem_in.h"

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
		ft_printf("FT_BFS-- CURRENT ROOM %s - visited %d - LEVEL\n", room->name, room->visited, room->level);
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
	ft_printf("FT_BFS ---- Created queue queue\n");
	ft_printf("FT_BFS ---- Found startroom %s\n", start->name);
	ft_enqueue(queue, start);
	ft_printf("FT_BFS ---- Enqueued endroom into queue\n");
	ft_bfs_queueing(queue);
	ft_printf("FT_BFS ---- Created queue\n");
	ft_print_arr_room(queue->prev);
	ft_free_queue(queue);
	return (0);
}
