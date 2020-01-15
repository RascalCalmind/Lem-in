/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lem_in.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:35:25 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/15 18:17:51 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

typedef struct  s_lemin
{
	char			*start;
	char			*end;
	t_rooms			*rooms;
	unsigned int	*ants;
}               t_lemin;

typedef struct  s_rooms
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	h;
	char			**conn;
}               t_rooms;

#endif
