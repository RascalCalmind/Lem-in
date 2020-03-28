/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ants.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 15:53:03 by lhageman       #+#    #+#                */
/*   Updated: 2020/03/28 18:52:32 by Lotte         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static int			ft_do_path(t_path *path, int *prev, t_lemin *lemin, \
	int has_moved)
{
	int	i;
	t_ant			*ant;

	i = 0;
	while (i < path->ants_len)
	{
		ant = path->ants[i];
		if (*prev != ant->cur && ant->cur <= path->len + 1)
		{
			ft_printf(ANSI_OCEAN_BLUE"L%i-%s", ant->num,
ant->cur == path->len + 1 ? lemin->end : path->room[ant->cur]->name);
			*prev = ant->cur;
			ant->cur += 1;
			if (i < path->ants_len)
				ft_printf(" ");
			has_moved = 1;
		}
		i += 1;
	}
	return (has_moved);
}

static int			ft_walk_ants(t_lemin *lemin)
{
	unsigned int	i;
	int				has_moved;
	int				prev;

	i = 0;
	has_moved = 0;
	prev = -1;
	while (i < lemin->path_count)
	{
		has_moved = ft_do_path(lemin->paths[i], &prev, lemin, has_moved);
		prev = -1;
		i++;
	}
	if (i > 0)
		ft_printf("\n"ANSI_RESET);
	return (has_moved);
}

static t_path		*find_best_path(t_lemin *lemin)
{
	unsigned int	i;
	t_path			*shortest;

	i = 0;
	shortest = lemin->paths[0];
	while (i < lemin->path_count)
	{
		if ((lemin->paths[i] != NULL && (shortest->len + shortest->ants_len) > \
		(lemin->paths[i]->len + lemin->paths[i]->ants_len)))
			shortest = lemin->paths[i];
		i++;
	}
	return (shortest);
}

int					ft_move_ants(t_lemin *lemin)
{
	t_path			*path;
	t_ant			*ant;
	unsigned int	i;

	i = 0;
	lemin->lines = 0;
	while (i < lemin->ants)
	{
		ant = (t_ant *)ft_memalloc(sizeof(t_ant));
		ant->cur = 1;
		ant->num = i + 1;
		path = find_best_path(lemin);
		path->ants[path->ants_len] = ant;
		path->ants_len++;
		i++;
	}
	ft_printf(ANSI_GREY_PINK"\n\n-----\n\nSOLUTION ANTS:\n\n"ANSI_RESET);
	while (ft_walk_ants(lemin))
		lemin->lines += 1;
	ft_printf(ANSI_GREY_PINK"-----\n\n"ANSI_RESET);
	return (lemin->lines);
}
