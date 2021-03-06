/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_max_flow.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/22 15:35:02 by wmisiedj       #+#    #+#                */
/*   Updated: 2020/02/24 16:32:12 by wmisiedj      ########   odam.nl         */
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

	end = ft_find_room(lemin, lemin->end);
	start = ft_find_room(lemin, lemin->start);

	flow = 0;
	dfs_flow = 1;
	while (start != NULL && end != NULL)
	{
		ft_bfs(lemin, start, end);
		if (end->level < 0)
			return (flow);
		ft_room_map(lemin, reset_iter);
		while (dfs_flow > 0)
		{
			dfs_flow = ft_dfs(lemin, start, end);
			if (dfs_flow > 0)
				flow += dfs_flow;
		}
	}
}