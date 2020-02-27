/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dfs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:14:06 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/27 19:04:34 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lem_in.h"

void		ft_add_room(t_lemin *lemin, t_room *room, int flow)
{
	int i;

	i = flow - 1;
	if (lemin->paths[i] == NULL)
		ft_printf("[ADD PATH] OH NO. ID %i\n", i);
	else
	{
		ft_printf("[ADD PATH] PATH ID [%d]: ROOM: %s\n", i, room->name);
		// IF PATH: 
		while (lemin->paths[i]->room[lemin->paths[i]->len] != NULL)
			lemin->paths[i]->len += 1;
		lemin->paths[i]->room[lemin->paths[i]->len] = room;
		ft_printf("[ADD PATH]: SAVED: %s IN POS: %d\n", lemin->paths[i]->room[lemin->paths[i]->len]->name, lemin->paths[i]->len);
	}
}

static int	ft_dfs_queueing(t_lemin *lemin, t_room *current, t_room *end, int flow)
{
	int curflow;
	t_edge *edge;

	curflow = 1;
	if (ft_strcmp(current->name, end->name) == 0)
		return (flow);
	if (flow == 0)
		return (flow);
	while (current->edges[current->dfs_iter] != NULL)
	{
		edge = current->edges[current->dfs_iter];
		if (ft_strcmp(edge->to->name, lemin->start) == 0)
		{
			printf("FOUND END OF PATH\n");
			lemin->path_count++;
		}
		ft_printf("edgecheck dfs-queueing %s, cl[%i] el[%i]\n", current->name, current->level, edge->to->level);
		if (edge->available && current->level <= edge->to->level)
		{
			curflow = ft_dfs_queueing(lemin, edge->to, end, edge->available);
			if (curflow > 0)
			{
				printf("To -> %s\n", edge->to->name);
				ft_add_room(lemin, edge->to, lemin->path_count);
				edge->available = 0;
				if (ft_strcmp(edge->to->name, lemin->start) != 0)
					edge->to->edges[edge->rev]->available = 1;
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
