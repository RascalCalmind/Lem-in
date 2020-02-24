/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dfs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:14:06 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/24 16:35:30 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lem_in.h"

static int	ft_dfs_queueing(t_lemin *lemin, t_room *current, t_room *end, int flow)
{
	int curflow;

	curflow = 1;
	if (ft_strcmp(current->name, end->name) == 0)
		return (flow);
	if (flow == 0)
		return (flow);

	while (current->edges[current->dfs_iter] != NULL)
	{
		
		if (current->edges[current->dfs_iter]->available && current->level < current->edges[current->dfs_iter]->to->level)
		{
			curflow = ft_dfs_queueing(lemin, current->edges[current->dfs_iter]->to, end, current->edges[current->dfs_iter]->available);
			if (curflow > 0)
			{
				printf("To -> %s\n", current->edges[current->dfs_iter]->to->name);
				current->edges[current->dfs_iter]->available = 0;
				return (curflow);
			}
		}
		current->dfs_iter++;
	}
	return (0);
}


int		ft_dfs(t_lemin *list, t_room *start, t_room *end)
{
	int inf;
	int dfs;

	inf = 0x7fffffff;
	dfs = ft_dfs_queueing(list, start, end, inf);

	ft_printf("FT_DFS ---- DONE DFS: %d\n", dfs);
	return (dfs);
}
