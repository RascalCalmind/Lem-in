/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ants.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 15:53:03 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/24 16:48:45 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int		print_ants(t_ant **ants, int total)
{
	int i;
	int cur;

	i = 0;
	while (i < total)
	{
		if (i != 0)
			ft_print(" ");
		if (ants[i] != NULL && ants[i]->path->room)
		{
			cur = ants[i]->cur;
			if (cur < ants[i]->path->len - 1)
			{
				ft_printf("L%i-%s", ants[i]->name, ants[i]->path->room[cur]->name);
				ants[i]->cur += 1;
			}
		}
		i += 1;
	}
	return (0);
}

void	ft_ass_ants(t_ant **ants, int amount)
{
	int i;

	i = 0;
	while (i < amount)
	{
		// ants[i] = (t_ant *)ft_memalloc(sizeof(t_ant *));
		if (!ants[i])
			return (-1);
		// ft_memset(ants[i], 0, 1);
		ants[i]->name = i;
		i += 1;
	}
}

void	ft_ass_room(t_ant **ants, t_path **paths, int atotal, int ptotal)
{
	int a;
	int p;

	a = 0;
	p = 0;
	while (a < atotal)
	{
		ants[a]->path = paths[p];
		a += 1;
		p += 1;
		if (p >= ptotal)
			p = 0;
	}
	return (0);
}

int		ants_test(void)
{
	t_ant **ants;
	int		total;

	ants = (t_ant **)ft_memalloc(sizeof(t_ant *) * total + 1);
	if (!ants)
		return (-1);
	ft_ass_ants(ants, total);
}