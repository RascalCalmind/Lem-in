/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lem_in.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:35:25 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/21 15:35:17 by lhageman      ########   odam.nl         */
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

typedef struct		s_edge
{
	// char			*from;
	// char			*to;
	struct s_room	*to;
	unsigned int	available : 1;
	// int				flow;
	// int				capacity;
	// int				rev;
}					t_edge;

typedef struct		s_room
{
	char			*name;
	unsigned int	x;
	unsigned int	y;
	double			f;
	double			g;
	double			h;
	int				level;
//	struct s_room	**links;
	struct s_edge	**edges;
	unsigned int	link_count;
	struct s_room	*next;
	unsigned int	visited : 1;
}					t_room;

typedef struct	s_queue
{
	t_room		**list; // list?
	t_room		**prev;
	int			len; // index queue / list length?
}				t_queue;

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
void				ft_print_arr_room(t_room **rooms);

int					ft_contains(char *str, char c);
int					ft_connection(char *str, t_lemin *list);
t_room				*ft_find_room(t_lemin *list, char *name);

int					ft_free_error_lem_rstr(t_lemin *list, t_rstr *file);

int					ft_is_command(char *str);
t_rstr				*ft_read_file(void);

int					ft_quicksort(t_room **open, int low, int high);
int					ft_bfs(t_lemin *list);
t_room				**ft_rec_path(t_room *start, t_room *end, t_room **rev, int len);

t_queue				*ft_queue(int size);
t_room				*ft_dequeue(t_queue *queue);
int					ft_enqueue(t_queue *queue, t_room *room);
int					ft_inqueue(t_queue *queue, t_room *room);
int					ft_free_queue(t_queue *queue);

#endif
