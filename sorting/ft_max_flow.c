/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_max_flow.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/22 15:35:02 by wmisiedj       #+#    #+#                */
/*   Updated: 2020/03/11 17:35:40 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lem_in.h"

void		reset_iter(t_room *room)
{
	if (room != NULL)
		room->dfs_iter = 0;
}

static t_path	**ft_create_paths(int rooms, int ants)
{
	t_path		**paths;
	int			i;

	i = 0;
	paths = (t_path **)ft_memalloc(sizeof(t_path *) * rooms + 1);
	while (i < rooms)
	{
		paths[i] = (t_path *)ft_memalloc(sizeof(t_path));
		paths[i]->room = (t_room **)\
		ft_memalloc(sizeof(t_room *) * rooms);
		paths[i]->ants = (t_ant **)\
		ft_memalloc(sizeof(t_ant *) * ants);
		i++;
	}
	return (paths);
}

int			ft_max_flow(t_lemin *lemin)
{
	printf("MAX FLOW START!\n");
	int				flow;
	int				dfs_flow;
	t_room			*start;
	t_room			*end;
	unsigned int	i;

	i = 0;
	end = ft_find_room(lemin, lemin->end);
	start = ft_find_room(lemin, lemin->start);
	lemin->paths = ft_create_paths(lemin->rooms, lemin->ants);
	flow = 0;
	while (start != NULL && end != NULL)
	{
		i += 1;
		if (i == 500)
			return (flow);
		ft_bfs(lemin, end);
		if (start->level < 0)
			return (flow);
		ft_room_map(lemin, reset_iter);
		dfs_flow = 1;
		while (dfs_flow > 0)
		{
			dfs_flow = ft_dfs(lemin, end, start);
			if (dfs_flow > 0)
				flow += dfs_flow;
		}
	}
	return (flow);
}
