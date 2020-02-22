/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_max_flow.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/22 15:35:02 by wmisiedj       #+#    #+#                */
/*   Updated: 2020/02/22 16:08:24 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lem_in.h"

int	ft_max_flow(t_lemin *list)
{
	int flow;
	int dfs_flow;
	t_room *start;
	t_room *end;

	end = ft_find_room(list, list->end);
	start = ft_find_room(list, list->start);

	flow = 0;
	dfs_flow = 1;
	while (start != NULL && end != NULL)
	{
		ft_bfs(list, start, end);
		if (end->level < 0)
			return (flow);
		while (dfs_flow > 0)
		{
			dfs_flow = ft_dfs(list, start, end);
			if (dfs_flow > 0)
				flow += dfs_flow;
		}
	}
}