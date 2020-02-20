/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_paths.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 17:28:39 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/20 16:23:08 by lhageman      ########   odam.nl         */
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
	ft_printf("rev:\n");
	ft_print_arr_room(rev, len);
	if (!p)
		return (NULL);
	while (i >= 0)
	{
		ft_printf("do we go here bruh %i\n", i);
		//p[j] = rev[i];
		temp = rev[i];
		p[j] = temp;
		i -= 1;
		j += 1;
	}
	ft_printf("path:\n");
	ft_print_arr_room(p, j + 1);
	free(rev);
	rev = NULL;
	// if (p[0] == start && p[j] == end)
	// 	return (p);
	// return (NULL);
	return (p);
}

//find end note then reverse search connection nodes located before the end node
//that will eventually connect the end node to the start node.
//instead of an array of nodes, create level nodes on the same spot in the array?
//or like linked binary lists? or not..
