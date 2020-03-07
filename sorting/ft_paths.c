/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_paths.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 17:28:39 by lhageman       #+#    #+#                */
/*   Updated: 2020/03/07 16:13:03 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lem_in.h"

t_room	**ft_rec_path(t_room *start, t_room *end, t_room **rev, int len)
{
	t_room	**p;
	t_room	*temp;
	int		i;
	int		j;

	i = len - 2;
	j = 0;
	if (i < 2)
		return (NULL);
	p = malloc(sizeof(t_room **));
	p = ft_memset(p, 0, i);
	ft_print_arr_room(rev);
	if (!p)
		return (NULL);
	while (i >= 0)
	{
		temp = rev[i];
		p[j] = temp;
		i -= 1;
		j += 1;
	}
	ft_print_arr_room(p);
	free(rev);
	rev = NULL;
	return (p);
}
