/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lem_in.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:35:25 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/08 14:47:13 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H

# include <unistd.h>
# include <stdlib.h>

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "./errors/ft_error.h"

#define MAX_HASHTABLE 10

typedef struct		s_room
{
	char			*name;
	unsigned int	x;
	unsigned int	y;
	double			f;
	double			g;
	double			h;
	struct s_room	**links;
	unsigned int	link_count;
	struct s_room	*next;
	unsigned int	visited : 1;
}					t_room;

typedef struct	s_path
{
	t_room		**open;
	t_room		**closed;
}				t_path;

typedef struct		s_lemin
{
	char			*start;
	char			*end;
	unsigned int	rooms;
	unsigned int	ants;
	t_room			*room[MAX_HASHTABLE];
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
t_lemin				*ft_create_lemin(t_rstr *file);
char				**ft_room_check(char *str);
int					ft_store_room(t_lemin *list, t_rstr *file);
void				ft_free_room(t_room *room);
void				ft_free_lemin(t_lemin *list);
void				ft_print_lemin(t_lemin *lemin);

int					ft_contains(char *str, char c);
int					ft_connection(char *str, t_lemin *list);

int					ft_free_error_lem_rstr(t_lemin *list, t_rstr *file);

int					ft_is_command(char *str);
t_rstr				*ft_read_file(void);

int					ft_quicksort(t_room **open, int low, int high);

#endif
