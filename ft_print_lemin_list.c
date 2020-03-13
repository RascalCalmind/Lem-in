/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_lemin_list.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 18:00:11 by lhageman       #+#    #+#                */
/*   Updated: 2020/03/11 11:00:45 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void		ft_print_paths(t_lemin *lemin, int max_flow)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (i < max_flow)
		ft_printf(ANSI_OCEAN_BLUE"\n-----\n\nPATHS FOUND:\n\n"ANSI_RESET);
	while (i < max_flow)
	{
		if (lemin->paths[i] && lemin->paths[i]->room != NULL)
		{
			ft_printf(ANSI_GREY_PURPLE"PATH[%i] WITH THE LENGTH OF %i:\n"\
			ANSI_RESET, i, lemin->paths[i]->len);
			while (j <= lemin->paths[i]->len)
			{
				ft_printf(ANSI_GREY_PINK"%s->"ANSI_RESET,\
				lemin->paths[i]->room[j]->name);
				j += 1;
			}
			ft_printf(ANSI_GREY_PINK"%s\n"ANSI_RESET, lemin->end);
			j = 0;
		}
		i += 1;
	}
	ft_printf(ANSI_OCEAN_BLUE"\n-----\n\n"ANSI_RESET);
}

void		ft_print_rstr(t_rstr *file)
{
	t_rstr *temp;

	temp = file;
	while (file->next != NULL)
	{
		ft_printf("%s\n", file->str);
		file = file->next;
	}
	file = temp;
}
