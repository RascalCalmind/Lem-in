/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bfs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:14:06 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/19 18:07:07 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lem_in.h"

int		ft_enqueue(t_path *paths, t_room *room)
{
	int i;

	i = 0;
	if (!paths || !room)
		return (-1);
	while (paths->queue[i])
		i += 1;
	paths->queue[i] = room;
	return (0);
}

int		ft_dequeue(t_path *paths)
{
	int i;

	i = 1;
	if (!paths)
		return (-1);
	if (paths->queue[0])
	{
		paths->queue[0]->visited = 1;
		paths->queue = NULL;
	}
	if (paths->queue[i] != NULL)
	{
		while (paths->queue[i])
		{
			ft_printf("FT_DEQUEUE ---- moving %s from %i to $i\n", paths->queue[i]->name, i, i - 1);
			paths->queue[i - 1] = paths->queue[i];
			paths->queue[i] = NULL;
			i += 1;
		}
	}
	return (0);
}

int		ft_inqueue(t_path *paths, t_room *room, int len)
{
	int i;

	i = 0;
	if (!paths)
		return (-1);
	if (paths->queue[0] == NULL)
		return (0);
	while (i < len && paths->queue[i] != NULL)
	{
		if (paths->queue[i] == room)
			return (0);
		i += 1;
	}
	return (1);
}

t_room		**ft_queueing(t_lemin *list, t_path *paths)
{
	int		i;
	int		j;
	t_room	**prev;
	t_room	*temp;

	i = 0;
	j = 0;
	prev = malloc(sizeof(t_room **));
	ft_memset(prev, 0, list->rooms);
	while (paths->queue[0] != NULL)
	{
		if (paths->queue[0]->links)
		{			
			temp = paths->queue[0];
			while (paths->queue[0]->links[i])
			{
				if (ft_inqueue(paths, paths->queue[0]->links[i], list->rooms) == 1 && paths->queue[0]->links[i]->visited == 0)
				{
					ft_printf("FT_ENQUEUEING ---- enqueueing path: %s\n", paths->queue[0]->links[i]->name);
					ft_enqueue(paths, paths->queue[0]->links[i]);
					prev[j] = paths->queue[0]->links[i];
					j += 1;
				}
				i += 1;
			}
			i = 0;
			paths->queue[0] = temp;
		}
		ft_printf("FT_ENQUEUEING ---- dequeueing path: %s\n", paths->queue[0]->name);
		ft_dequeue(paths);
	}
	return (prev);
}

int		ft_bfs(t_lemin *list)
{
	t_path	*paths;
	t_room	*start;
	t_room	*end;
	t_room	**rev;
	t_room	**fp;

	paths = malloc(sizeof(t_path *));
	if (!paths)
		return (-1);
	paths->queue = malloc(sizeof(t_room *) * list->rooms);
	if (!paths->queue)
	{
		free(paths);
		paths = NULL;
		return (-1);
	}
	ft_printf("FT_BFS ---- Created paths queue\n");
	end = ft_find_room(list, list->end);
	if (end == NULL)
		return (-1);
	ft_printf("FT_BFS ---- Found endroom %s\n", end->name);
	ft_enqueue(paths, end);
	ft_printf("FT_BFS ---- Enqueued endroom into queue\n");
	rev = ft_queueing(list, paths);
	ft_printf("FT_BFS ---- Created paths\n");
	start = ft_find_room(list, list->start);
	if (start == NULL)
		return (-1);
	ft_printf("FT_BFS ---- Found startroom %s\n", start->name);
	fp = ft_rec_path(start, end, rev);
	ft_printf("FT_BFS ---- Recreated path from end to start\n");
	return (0);
}
