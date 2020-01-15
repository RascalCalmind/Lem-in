/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_char_arr_len.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/29 14:56:52 by lhageman       #+#    #+#                */
/*   Updated: 2019/12/29 15:00:00 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_chararrlen(char **arr)
{
	int i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i += 1;
	return (i);
}
