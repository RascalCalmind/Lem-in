/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lem_in.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:34:10 by lhageman      #+#    #+#                 */
/*   Updated: 2020/05/15 16:32:39 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int				ft_read_ants(t_lemin *lemin)
{
	while (lemin->line->str[0] == '#' && lemin->line->str[1] != '#')
		lemin->line = lemin->line->next;
	if (!lemin->line->str || ft_contains(lemin->line->str, ' ') ||\
	ft_strcmp(lemin->line->str, "") == 0 || ft_check_int(lemin->line->str) != 0)
		return (ERR_FILE);
	lemin->ants = ft_atoi(lemin->line->str);
	if (lemin->ants <= 0)
		return (ERR_NO_ANTS);
	lemin->line = lemin->line->next;
	return (1);
}

int				ft_read_connections(t_lemin *lemin)
{
	while (lemin->line->next != NULL)
	{
		if (lemin->line->str[0] == '#')
			;
		else if (ft_contains(lemin->line->str, '-') == 0)
			return (ERR_FILE);
		else if (ft_connection(lemin->line->str, lemin) < 0)
			return (ERR_CONNECTION);
		lemin->line = lemin->line->next;
	}
	return (1);
}

static void		ft_lem_flags(int argc, char **argv, t_lemin *lemin)
{
	if (argc <= 1)
		return ;
	if ((ft_strcmp(argv[1], "-l") == 0 && lemin->lines > 0) ||\
		(ft_strcmp(argv[1], "-pl") == 0 && lemin->lines > 0) ||\
		(ft_strcmp(argv[1], "-lp") == 0 && lemin->lines > 0))
		ft_printf("Amount of lines used: %i\n", lemin->lines);
	if ((ft_strcmp(argv[1], "-p") == 0 && lemin->lines == -3) ||\
		(ft_strcmp(argv[1], "-pl") == 0 && lemin->lines == -3) ||\
		(ft_strcmp(argv[1], "-lp") == 0 && lemin->lines == -3))
		ft_print_paths(lemin, lemin->max_flow);
}

static t_lemin	*ft_lem_in(t_lemin *lemin)
{
	lemin = ft_create_lemin(lemin);
	if (lemin == NULL || lemin->rooms < 2)
	{
		ft_free_error(lemin, lemin->rooms < 2 ?\
		ERR_NO_START_END : ERR_MEM);
		return (NULL);
	}
	if (ft_create_lists(lemin) == -1)
		return (NULL);
	lemin->max_flow = ft_max_flow(lemin);
	if (lemin->max_flow <= 0)
	{
		ft_free_error(lemin, ERR_NO_PATHS);
		return (NULL);
	}
	ft_print_rstr(lemin->line);
	return (lemin);
}

int				main(int argc, char **argv)
{
	t_lemin		*lemin;

	lemin = (t_lemin *)ft_memalloc(sizeof(t_lemin));
	if (!lemin)
	{
		ft_error(ERR_MEM);
		return (0);
	}
	lemin->file = ft_read_file();
	lemin->line = lemin->file;
	if (!lemin->line)
		return (0);
	lemin = ft_lem_in(lemin);
	if (lemin == NULL)
		return (-1);
	ft_lem_flags(argc, argv, lemin);
	lemin->lines = ft_move_ants(lemin);
	ft_lem_flags(argc, argv, lemin);
	if (lemin->file)
		ft_free_rstr(lemin->file);
	if (lemin)
		ft_free_lemin(lemin);
	return (0);
}
