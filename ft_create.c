/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_create.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 13:55:12 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/04 20:58:38 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int			ft_create_room(t_room *room)
{
	if (!room)
		return (-1);
	room->name = NULL;
	room->x = 0;
	room->y = 0;
	room->h = 0;
	room->links = NULL;
	room->next = NULL;
	return (0);
}

int			ft_create_lemin(t_lemin *list, int size)
{
	t_room	**rooms;
	int i;

	i = 0;
	rooms = ft_memalloc(sizeof(t_room **) * size);
	if (!rooms)
		return (-1);
	list->start = NULL;
	list->end = NULL;
	list->room = rooms;
	list->ants = 0;
	list->rooms = size;
	ft_printf("end:[%s]\tstart:[%s]\n---\n", list->end, list->start);
	return (0);
}
