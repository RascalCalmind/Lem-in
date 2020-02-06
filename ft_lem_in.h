/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lem_in.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:35:25 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/06 14:22:23 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H

# include <unistd.h>
# include <stdlib.h>

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "./errors/ft_error.h"

#define MAX_HASHTABLE 9999

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
	unsigned int	rooms;
	unsigned int	ants;
	t_room			**room;
}					t_lemin;

typedef struct		s_rstr
{
	char			*str;
	struct s_rstr	*next;
}					t_rstr;

int					ft_free_char_arr(char **arr, int len);
unsigned int		ft_hash_sdbm(char *str, unsigned int max_int);
void				ft_free_rstr(t_rstr *list);

int					ft_create_room(t_room *room);
int					ft_create_lemin(t_lemin *list, int rooms);
char				**ft_room_check(char *str);
int					ft_store_room(t_lemin *list, t_rstr *file);
void				ft_free_room(t_room *room, unsigned int rooms);
void				ft_free_lemin(t_lemin *list);
void				ft_print_lemin(t_lemin *lemin);

int					ft_contains(char *str, char c);

int					ft_free_error_lem_rstr(t_lemin *list, t_rstr *file);

#endif
