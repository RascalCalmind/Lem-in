/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_room_check.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 14:29:05 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/04 17:31:01 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

/**
 * Checks if room line is valid, returns arumgents (name / x / y)
 */

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
		ft_printf("ft_room_check\t\tarr[%i]:%s\n", i, arr[i]);
		i += 1;
	}
	return (arr);
}
