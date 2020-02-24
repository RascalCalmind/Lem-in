/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_create.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 13:55:12 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/24 16:04:06 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static int	ft_room_count(t_rstr *file)
{
	int		cnt;
	char	**arr;

	cnt = 0;
	while (file->next != NULL)
	{
		if (file->str && ft_contains(file->str, ' ') == 2)
		{
			arr = ft_strsplit(file->str, ' ');
			if (ft_check_int(arr[1]) == 0 && ft_check_int(arr[2]) == 0)
				cnt += 1;
			if (arr)
				ft_free_char_arr(arr, 4);
		}
		file = file->next;
	}
	if (file->str && ft_contains(file->str, ' ') == 2)
	{
		arr = ft_strsplit(file->str, ' ');
		if (ft_check_int(arr[1]) == 0 && ft_check_int(arr[2]) == 0)
			cnt += 1;
		if (arr)
			ft_free_char_arr(arr, 4);
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
	lemin->iter = (unsigned int *)ft_memalloc(sizeof(unsigned int) * lemin->rooms);
	return (lemin);
}
