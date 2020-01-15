/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_int_arr_len.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/29 14:58:40 by lhageman       #+#    #+#                */
/*   Updated: 2019/12/29 14:59:34 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_intarrlen(int *arr)
{
	int i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i += 1;
	return (i);
}
