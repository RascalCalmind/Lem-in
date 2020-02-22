/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_queue.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 14:35:04 by wmisiedj       #+#    #+#                */
/*   Updated: 2020/02/22 14:40:21 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lem_in.h"

t_queue	*ft_queue(int size)
{
	t_queue *queue;

	queue = ft_memalloc(sizeof(t_queue));
	if (queue == NULL)
		return (NULL);
	queue->list = ft_memalloc(sizeof(t_room *) * (size + 1));
	if (queue->list == NULL)
	{
		free(queue);
		return (NULL);
	}
	queue->prev = (t_room **)ft_memalloc(sizeof(t_room *) * (size + 1));
	if (queue->prev == NULL)
	{
		free(queue->list);
		free(queue);
		return (NULL);
	}
	queue->len = 0;
	return (queue);
}

int		ft_enqueue(t_queue *queue, t_room *room)
{
	ft_printf("FT_ENQUEUEUEUEUEUEU-----\n");
	if (!queue || !room)
		return (-1);
	queue->list[queue->len] = room;
	room->visited = 1;
	queue->len += 1;
	return (0);
}

t_room	*ft_dequeue(t_queue *queue)
{
	int 	i;
	t_room	*room;

	i = 1;
	if (!queue || !queue->len || queue->list[0] == NULL)
		return (NULL);
	room = queue->list[0];
	while (i <= queue->len && queue->list[i] != NULL)
	{
		queue->list[i - 1] = queue->list[i];
		queue->list[i] = NULL;
		i += 1;
	}
	queue->len -= 1;
	return (room);
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

int		ft_free_queue(t_queue *queue)
{
	if (queue == NULL)
		return (1);
	if (queue->list != NULL)
	{
		free(queue->list);
		queue->list = NULL;
	}
	if (queue->prev != NULL)
	{
		free(queue->prev);
		queue->prev = NULL;
	}
	if (queue != NULL)
	{
		free(queue);
		queue = NULL;
	}
	return (1);
}