/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bfs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:14:06 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/14 13:42:13 by lhageman      ########   odam.nl         */
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
		paths->queue[0]->visited = 0;
		paths->queue = NULL;
	}
	while (paths->queue[i])
	{
		paths->queue[i - 1] = paths->queue[i];
		paths->queue[i] = NULL;
		i += 1;
	}
	return (0);
}

int		ft_inqueue(t_path *paths)
{
	if (!paths)
		return (-1);
	if (paths->queue[0] == NULL)
		return (0);
	return (1);
}

int		ft_bfs(t_lemin *list)
{
	t_path	*paths;

	paths = malloc(sizeof(t_path *));
	paths->queue = malloc(sizeof(t_room *) * list->rooms);
	return (0);
}
