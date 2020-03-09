/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ants.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 15:53:03 by lhageman       #+#    #+#                */
/*   Updated: 2020/03/09 17:32:09 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static int		ft_print_ants(t_lemin *lemin)
{
	unsigned int	p;
	int				a;
	int 			cur;
	int 			prev;
	int 			test;

	p = 0;
	prev = -1;
	test = -1;
	while (p < lemin->path_count)
	{
		a = 0;
		while (a < lemin->paths[p]->ants_len)
		{
			cur = lemin->paths[p]->ants[a]->cur;
			if (prev != cur && cur <= lemin->paths[p]->len)
			{
				ft_printf(ANSI_OCEAN_BLUE"L%i-%s", lemin->paths[p]->ants[a]->num,\
				lemin->paths[p]->room[cur]->name);
				lemin->paths[p]->ants[a]->cur += 1;
				prev = cur;
				if (p + 1 < lemin->path_count)
					ft_printf(" ");
				test = 0;
			}
			else if (prev != cur && cur == lemin->paths[p]->len + 1)
			{
				ft_printf(ANSI_OCEAN_BLUE"L%i-%s", lemin->paths[p]->ants[a]->num, lemin->end);
				lemin->paths[p]->ants[a]->cur += 1;
				prev = cur;
				if (p + 1 < lemin->path_count)
					ft_printf(" ");
				test = 0;
			}
			a += 1;
		}
		prev = -1;
		p += 1;
	}
	if (p > 0)
		ft_printf("\n"ANSI_RESET);
	if (test == 0)
		return (0);
	return (1);
}

static t_path	*find_best_path(t_lemin *lemin)
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

int				place_ants(t_lemin *lemin)
{
	t_path			*path;
	t_ant			*ant;
	unsigned int	i;
	int				ret;
	int				lines;

	i = 0;
	ret = -1;
	lines = -1;
	while (i < lemin->ants)
	{
		ant = (t_ant *)ft_memalloc(sizeof(t_ant));
		ant->cur = 0;
		ant->num = i + 1;
		path = find_best_path(lemin);
		path->ants[path->ants_len] = ant;
		path->ants_len++;
		i++;
	}
	if (ret != 1)
		ft_printf(ANSI_GREY_PINK"\n\n-----\n\nSOLUTION ANTS:\n\n"ANSI_RESET);
	while (ret != 1)
	{
		ret = ft_print_ants(lemin);
		lines += 1;
	}
	ft_printf(ANSI_GREY_PINK"-----\n\n"ANSI_RESET);
	return (lines);
}
