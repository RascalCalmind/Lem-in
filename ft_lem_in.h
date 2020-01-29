/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lem_in.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:35:25 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/25 16:19:57 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"


typedef struct  	s_room
{
	char			*name;
	unsigned int	x;
	unsigned int	y;
	unsigned int	h;
	struct t_room	**conn;
	struct t_room	*next;
}               	t_room;

typedef struct  	s_lemin
{
	char			*start;
	char			*end;
	t_room			*room;
	unsigned int	ants;
}               	t_lemin;


//int					ft_create_room(t_room *room);
//int					ft_create_lemin(t_lemin *list);
//void				ft_free_room(t_room *room);
//void				ft_free_lemin(t_lemin *list);

#endif
