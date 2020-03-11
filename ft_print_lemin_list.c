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
			ft_printf(ANSI_GREY_PURPLE"PATH[%i] WITH THE LENGTH OF %i:\n"ANSI_RESET, i, lemin->paths[i]->len);
			while (j <= lemin->paths[i]->len)
			{
				ft_printf(ANSI_GREY_PINK"%s->"ANSI_RESET, lemin->paths[i]->room[j]->name);
				j += 1;
			}
			ft_printf(ANSI_GREY_PINK"%s\n"ANSI_RESET, lemin->end);
			j = 0;
		}
		i += 1;
	}
	ft_printf(ANSI_OCEAN_BLUE"\n-----\n\n"ANSI_RESET);
}

void		ft_print_lemin(t_lemin *lemin)
{
	unsigned int	i;
	int				j;
	t_room			*temp;

	i = 0;
	j = 0;
	temp = NULL;
	if (lemin->ants)
		ft_printf("Amount of ants:\t\t %i\n", lemin->ants);
	if (lemin->start)
		ft_printf("Starting room name:\t %s\n", lemin->start);
	if (lemin->end)
		ft_printf("End room name:\t\t %s\n", lemin->end);
	if (lemin->rooms)
		ft_printf("Total amount of rooms:\t %i\n", lemin->rooms);
	ft_printf("--------------------------------------------\n");
	if (lemin->room[0])
	{
		while (i < MAX_HASHTABLE)
		{
			if (lemin->room[i] != NULL)
			{
				temp = lemin->room[i];
				while (lemin->room[i] != NULL)
				{
					ft_printf("Position in list:\t\t%i\n", i);
					if (lemin->room[i]->name)
						ft_printf("Room name:\t\t\t%s\n", lemin->room[i]->name);
					if (lemin->room[i]->x >= 0 && lemin->room[i]->y >= 0)
						ft_printf("Room coordinates:\t\t(%i,%i)\n", lemin->room[i]->x, lemin->room[i]->y);
					ft_printf("Visited = %i\n", lemin->room[i]->visited);
					if (lemin->room[i]->edges != NULL)
					{
						ft_printf("room links:\t\t\t");
						while (lemin->room[i]->edges[j] != NULL)
						{
							ft_printf("%s, ", lemin->room[i]->edges[j]->to->name);
							j += 1;
						}
						j = 0;
						ft_printf("\n");
					}
					lemin->room[i] = lemin->room[i]->next;
					ft_printf("--------------------------------------------\n");
				}
				lemin->room[i] = temp;
			}
			i += 1;
		}
	}
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

void		ft_print_arr_room(t_room **rooms)
{
	int i;

	i = 0;
	while (rooms[i] != NULL)
	{
		ft_printf("Room: '%s' - Level: %i", rooms[i]->name, rooms[i]->level);
		if (rooms[i + 1] != NULL)
			ft_printf("->\n");
		i += 1;
	}
	ft_printf("\n");
}
