/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_lemin_list.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 18:00:11 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/03 18:03:58 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void		ft_print_lemin(t_lemin *lemin)
{
	unsigned int	i;
	t_room			*temp;

	i = 0;
	temp = NULL;
	if (lemin->ants)
		ft_printf("Amount of ants:\t\t %i\n", lemin->ants);
	if (lemin->start)
		ft_printf("Starting room name:\t %s\n", lemin->start);
	if (lemin->end)
		ft_printf("End room name:\t\t %s\n", lemin->end);
	if (lemin->rooms)
		ft_printf("Total amount of rooms:\t %i\n", lemin->rooms);
	if (lemin->room)
	{
		while (i < lemin->rooms)
		{
			if (lemin->room[i] != NULL)
			{
				temp = lemin->room[i];
				ft_printf("Position in list: %i\n", i);
				while (lemin->room[i]->next != NULL)
				{
					if (lemin->room[i]->name)
						ft_printf("Room name:\t\t %s\n", lemin->room[i]->name);
					if (lemin->room[i]->x >= 0 && lemin->room[i]->y >= 0)
						ft_printf("Room coordinates:\t %i,%i\n", lemin->room[i]->x, lemin->room[i]->y);
					if (lemin->room[i]->h)
						ft_printf("Euclidian distance to the end:\t %i\n", lemin->room[i]->h);
					if (lemin->room[i]->next)
						lemin->room[i] = lemin->room[i]->next;
				}
				if (lemin->room[i]->name)
					ft_printf("Room name:\t\t %s\n", lemin->room[i]->name);
				if (lemin->room[i]->x >= 0 && lemin->room[i]->y >= 0)
					ft_printf("Room coordinates:\t %i,%i\n", lemin->room[i]->x, lemin->room[i]->y);
				if (lemin->room[i]->h)
					ft_printf("Euclidian distance to the end:\t %i\n", lemin->room[i]->h);
				lemin->room[i] = temp;
			}
			i += 1;
		}
	}
}