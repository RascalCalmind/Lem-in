/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bfs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:14:06 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/20 17:01:48 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lem_in.h"

int		ft_enqueue(t_queue *queue, t_room *room)
{
	if (!queue || !room)
		return (-1);
	ft_printf("----\nFT_ENQUEUE ---- enqueueing: %s on place %i\n", room->name, queue->len);
	queue->list[queue->len] = room;
	room->visited = 1;
	queue->len += 1;
	return (0);
}

int		ft_dequeue(t_queue *queue)
{
	int i;

	i = 1;
	if (!queue || queue->len < 1)
		return (-1);
	if (queue->list[0] != NULL)
	{
		ft_printf("---\nFT_DEQUEUE ---- dequeueing: %s\n", queue->list[0]->name);

		queue->list[0] = NULL;
	}
	if (queue->len > 1 && queue->list[i] != NULL)
	{
		while (i <= queue->len + 1 && queue->list[i] != NULL)
		{
			ft_printf("FT_DEQUEUE ---- rooms in queue %i and i %i\n", queue->len, i);
			ft_printf("FT_DEQUEUE ---- moving %s from %i to %i\n", queue->list[i]->name, i, (i - 1));
			queue->list[i - 1] = queue->list[i];
			queue->list[i] = NULL;
			i += 1;
		}
	}
	queue->len -= 1;
	return (0);
}

int		ft_inqueue(t_queue *queue, t_room *room)
{
	int i;

	i = 0;
	if (!queue)
		return (-1);
	if (queue->list[0] == NULL)
		return (0);
	while (i <= queue->len && queue->list[i] != NULL)
	{
		if (queue->list[i] == room)
			return (0);
		i += 1;
	}
	return (1);
}

t_room		**ft_queueing(t_lemin *list, t_queue *queue)
{
	int		i;
	int		j;
	int		level;
	t_room	**prev;
	t_room	*temp;

	i = 0;
	j = 0;
	level = 1;
	prev = (t_room **)ft_memalloc(sizeof(t_room *) * (list->rooms + 1));
	while (queue->list[0] != NULL)
	{
		if (queue->list[0]->links)
		{
			temp = queue->list[0];
			while (queue->list[0]->links[i])
			{
				if (ft_inqueue(queue, queue->list[0]->links[i]) == 1 && queue->list[0]->links[i]->visited == 0)
				{
					ft_printf("FT_ENQUEUEING ---- enqueueing path: %s\n", queue->list[0]->links[i]->name);
					ft_enqueue(queue, queue->list[0]->links[i]);
					prev[j] = queue->list[0]->links[i];
					queue->list[0]->links[i]->level = level;
					//prev[j] = queue->list[0];
					j += 1;
				}
				i += 1;
			}
			level += 1;
			i = 0;
			queue->list[0] = temp;
		}
		ft_printf("FT_ENQUEUEING ---- dequeueing path: %s\n", queue->list[0]->name);
		ft_dequeue(queue);
	}
	return (prev);
}

int		ft_bfs(t_lemin *list)
{
	t_queue	*queue;
	t_room	*start;
	t_room	*end;
	t_room	**rev;
	// t_room	**fp;

	queue = ft_memalloc(sizeof(t_queue *));
	if (!queue)
		return (-1);
	queue->list = ft_memalloc(sizeof(t_room *) * (list->rooms + 1));
	queue->len = 0;
	if (!queue->list)
	{
		free(queue);
		queue = NULL;
		return (-1);
	}
	ft_printf("FT_BFS ---- Created queue queue\n");
	end = ft_find_room(list, list->end);
	if (end == NULL)
		return (-1);
	ft_printf("FT_BFS ---- Found endroom %s\n", end->name);
	start = ft_find_room(list, list->start);
	if (start == NULL)
		return (-1);
	ft_printf("FT_BFS ---- Found startroom %s\n", start->name);
	ft_enqueue(queue, start);
	ft_printf("FT_BFS ---- Enqueued endroom into queue\n");
	rev = ft_queueing(list, queue);
	ft_printf("FT_BFS ---- Created queue\n");
	ft_print_arr_room(rev);
	free(rev);
	free(queue->list);
	free(queue);
	// fp = ft_rec_path(start, end, rev, queue->tlen);
	// ft_printf("FT_BFS ---- Recreated path from end to start\n");
	// free(fp);
	// fp = NULL;
	return (0);
}
