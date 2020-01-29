/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lem_in.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:35:25 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/29 15:42:35 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H

# include <unistd.h>
# include <stdlib.h>

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "./errors/ft_error.h"

typedef struct		s_room
{
	char			*name;
	unsigned int	x;
	unsigned int	y;
	unsigned int	h;
	struct s_room	**links;
	struct s_room	*next;
	unsigned int	visited : 1;
}					t_room;

typedef struct		s_lemin
{
	char			*start;
	char			*end;
	t_room			**room;
	unsigned int	ants;
}					t_lemin;

typedef struct		s_rstr
{
	char			*str;
	struct s_rstr	*next;
}					t_rstr;

int         		ft_free_char_arr(char **arr, int len);
int					ft_hashf(char *name);

//int					ft_create_room(t_room *room);
//int					ft_create_lemin(t_lemin *list);
//void				ft_free_room(t_room *room);
//void				ft_free_lemin(t_lemin *list);

#endif
