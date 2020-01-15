/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lem_in.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:34:10 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/15 17:58:32 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int	ft_error(void)
{
	ft_dprintf(2, "Error\n");
	return (-1);
}

int	main(int argc, char **argv)
{
	char *line;
	char *start;
	char *end;
	int s;
	int e;

	s = 0;
	e = 0;
	while (get_next_line(STDIN_FILENO, &line))
	{
		ft_printf("LINE STDIN: %s\n", line);
		if (line[0] == 'L')
			return (ft_error());
		if (ft_strcmp(line, "##start") == 0)
			s = 1;
		if (ft_strcmp(line, "##end") == 0)
			e = 1;
		if (s == 1 && line[0] != '#')
		{
			start = line;
			s = 0;
		}
		if (e == 1 && line[0] != '#')
		{
			end = line;
			e = 0;
		}
	}
	ft_printf("start: %s, end: %s", start, end);
	return (0);
}
