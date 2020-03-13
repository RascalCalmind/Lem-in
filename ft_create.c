/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_create.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 13:55:12 by lhageman       #+#    #+#                */
/*   Updated: 2020/03/11 15:57:05 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static int	ft_room_count(t_rstr *file)
{
	int		cnt;
	char	**arr;
	t_rstr	*str;

	cnt = 0;
	str = file;
	while (str != NULL)
	{
		if (str->str && ft_contains(str->str, ' ') == 2)
		{
			arr = ft_strsplit(str->str, ' ');
			if (ft_check_int(arr[1]) == 0 && ft_check_int(arr[2]) == 0)
				cnt += 1;
			if (arr)
				ft_free_char_arr(arr, 4);
		}
		str = str->next;
	}
	return (cnt);
}

t_lemin		*ft_create_lemin(t_rstr *file)
{
	t_lemin *lemin;

	lemin = (t_lemin *)ft_memalloc(sizeof(t_lemin));
	if (lemin == NULL)
		return (NULL);
	lemin->rooms = ft_room_count(file);
	lemin->iter = (unsigned int *)ft_memalloc(sizeof(unsigned int)\
	* lemin->rooms);
	lemin->lines = 0;
	return (lemin);
}
