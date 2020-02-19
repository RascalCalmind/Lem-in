/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_paths.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 17:28:39 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/19 17:51:21 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lem_in.h"

t_room	**ft_rec_path(t_room *start, t_room *end, t_room **rev)
{
	t_room	**p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (rev[i] != NULL)
		i += 1;
	if (i < 2)
		return (NULL);
	p = malloc(sizeof(t_room **));
	p = ft_memset(p, 0, i);
	if (!p)
		return (NULL);
	while (i >= 0)
	{
		p[j] = rev[i];
		i -= 1;
		j += 1;
	}
	ft_print_arr_room(p);
	if (p[0] == start && p[j] == end)
		return (p);
	free(p);
	p = NULL;
	return (NULL);
}
