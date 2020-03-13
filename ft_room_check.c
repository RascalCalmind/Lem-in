/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_room_check.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 14:29:05 by lhageman       #+#    #+#                */
/*   Updated: 2020/03/07 16:25:06 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int		ft_is_command(char *str)
{
	return (ft_strcmp(str, "##start") == 0 || ft_strcmp(str, "##end") == 0);
}

char	**ft_room_check(char *str)
{
	char	**arr;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	arr = ft_strsplit(str, ' ');
	while (i < 3)
	{
		if (i > 0)
		{
			ret = ft_check_int(arr[i]);
			if (ret != 0)
				return (NULL);
		}
		i += 1;
	}
	return (arr);
}
