/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_max_flow.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/22 15:35:02 by wmisiedj       #+#    #+#                */
/*   Updated: 2020/02/28 16:17:23 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lem_in.h"

void	reset_iter(t_room *room) {
	if (room != NULL)
	{
		printf("RESET ITER: Resetting room dfs iter: %s\n", room->name);
		room->dfs_iter = 0;
	}
}

int	ft_max_flow(t_lemin *lemin)
{
	int flow;
	int dfs_flow;
	t_room *start;
	t_room *end;
	int i = 0;

	end = ft_find_room(lemin, lemin->end);
	start = ft_find_room(lemin, lemin->start);
	lemin->paths = (t_path **)ft_memalloc(sizeof(t_path *) * lemin->rooms + 1);
	while (i < lemin->rooms)
	{
		lemin->paths[i] = (t_path *)ft_memalloc(sizeof(t_path));
		lemin->paths[i]->room = (t_room **)ft_memalloc(sizeof(t_room *) * lemin->rooms);
		i += 1;
	}
	flow = 0;
	dfs_flow = 1;
	while (start != NULL && end != NULL)
	{
		//ft_bfs(lemin, start, end);
		ft_bfs(lemin, end, start);
		dfs_flow = 1;
		// if (end->level < 0)
		// 	return (flow);
		ft_printf("start->level: %s after bfs [%i]\n", start->name, start->level);
		if (start->level < 0)
			return (flow);
		ft_room_map(lemin, reset_iter);
		while (dfs_flow > 0)
		{
			// dfs_flow = ft_dfs(lemin, start, end);
			dfs_flow = ft_dfs(lemin, end, start);
			if (dfs_flow > 0)
				flow += dfs_flow;
		}
	}
	return (flow);
}