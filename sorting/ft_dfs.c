/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dfs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:14:06 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/22 16:04:09 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lem_in.h"

static int	ft_dfs_queueing(t_room *current, t_room *end, int flow)
{
	int i;
	int curflow;

	i = 0;
	curflow = 1;
	if (ft_strcmp(current->name, end->name) == 0)
		return (flow);
	if (flow == 0)
		return (flow);

	while (current->edges[i] != NULL)
	{
		if (current->edges[i]->available && current->level < current->edges[i]->to->level)
		{
			curflow = ft_dfs_queueing(current->edges[i]->to, end, current->edges[i]->available);
			if (curflow > 0)
			{
				current->edges[i]->available = 0;
				return (curflow);
			}
		}
		i++;
	}
	return (0);
}

int		ft_dfs(t_lemin *list, t_room *start, t_room *end)
{
	int inf;
	int dfs;

	inf = 0x7fffffff;
	dfs = ft_dfs_queueing(start, end, inf);

	ft_printf("FT_DFS ---- DONE DFS: %d\n", dfs);
	return (dfs);
}
