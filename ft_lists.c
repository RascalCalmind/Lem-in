/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lists.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/15 14:59:06 by lottehagema   #+#    #+#                 */
/*   Updated: 2020/05/15 16:57:02 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_lem_in.h"

static int		ft_is_command(char *str)
{
	return (ft_strcmp(str, "##start") == 0 || ft_strcmp(str, "##end") == 0);
}

static int		ft_handle_command_line(t_lemin *lemin)
{
	char	**args;
	char	*command;

	command = ft_strdup(lemin->line->str);
	if (!lemin->line->str)
		return (ft_free_error(lemin, ERR_MEM));
	while (lemin->line->str[0] == '#')
		lemin->line = lemin->line->next;
	args = ft_strsplit(lemin->line->str, ' ');
	if ((ft_strcmp(command, "##start") == 0 && lemin->start != NULL) ||
		(ft_strcmp(command, "##end") == 0 && lemin->end != NULL))
		ft_error(ERR_DOUBLE_COMMANDS);
	else if (ft_strcmp(command, "##start") == 0)
		lemin->start = ft_strdup(args[0]);
	else if (ft_strcmp(command, "##end") == 0)
		lemin->end = ft_strdup(args[0]);
	if (lemin->start && lemin->end && ft_strcmp(lemin->start, lemin->end)\
		== 0)
		ft_error(ERR_DOUBLE_COMMANDS);
	ft_store_room(lemin);
	ft_free_char_arr(args, 4);
	free(command);
	return (1);
}

static int		ft_read_rooms(t_lemin *lemin)
{
	while (lemin->line && lemin->line->next != NULL)
	{
		if (ft_strcmp(lemin->line->str, "") == 0)
			return (ERR_FILE);
		else if (lemin->line->str[0] == '#' && lemin->line->str[1] != '#')
			;
		else if (ft_is_command(lemin->line->str))
			ft_handle_command_line(lemin);
		else if (ft_contains(lemin->line->str, ' ') == 2)
		{
			if (ft_store_room(lemin) != 1)
				return (-1);
		}
		else if (ft_contains(lemin->line->str, '-')
			&& !ft_contains(lemin->line->str, ' '))
			break ;
		lemin->line = lemin->line->next;
	}
	if (lemin->end == NULL || lemin->start == NULL)
		return (ERR_NO_START_END);
	return (1);
}

int				ft_create_lists(t_lemin *lemin)
{
	int ret;

	ret = ft_read_ants(lemin);
	if (ret <= 0)
		return (ft_free_error(lemin, ret));
	ret = ft_read_rooms(lemin);
	if (ret <= 0)
		return (ft_free_error(lemin, ret));
	ret = ft_read_connections(lemin);
	if (ret <= 0)
		return (ft_free_error(lemin, ret));
	return (1);
}
