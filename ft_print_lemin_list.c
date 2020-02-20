/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_lemin_list.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 18:00:11 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/20 19:33:30 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void		ft_print_lemin(t_lemin *lemin)
{
	//ft_printf("PRINTING LEMIN LISTS \n\n");
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
	if (lemin->room)
	{
		while (i < MAX_HASHTABLE)
		{
			if (lemin->room[i] != NULL)
			{
				temp = lemin->room[i];
				//ft_printf("INITIALR ROOM: %s\n", lemin->room[i]->name);
				while (lemin->room[i] != NULL)
				{
					ft_printf("Position in list:\t\t%i\n", i);
					if (lemin->room[i]->name)
						ft_printf("Room name:\t\t\t%s\n", lemin->room[i]->name);
					if (lemin->room[i]->x >= 0 && lemin->room[i]->y >= 0)
						ft_printf("Room coordinates:\t\t(%i,%i)\n", lemin->room[i]->x, lemin->room[i]->y);
					if (lemin->room[i]->h)
						ft_printf("Heuridian distance to the end:\t%f\n", lemin->room[i]->h);
					if (lemin->room[i]->links != NULL)
					{
						ft_printf("room links:\t\t\t");
						while (lemin->room[i]->links[j] != NULL)
						{
							ft_printf("%s, ", lemin->room[i]->links[j]->name);
							j += 1;
						}
						j = 0;
						ft_printf("\n");
					}
					lemin->room[i] = lemin->room[i]->next;
					ft_printf("--------------------------------------------\n");
				}
				lemin->room[i] = temp;
				//ft_printf("SHOULD RESET ROOM: %s\n", lemin->room[i]->name);
			}
			i += 1;
		}
	}
}

void	ft_print_arr_room(t_room **rooms)
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
