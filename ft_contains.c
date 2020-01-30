/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_contains.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 13:54:26 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/30 15:02:22 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int		ft_contains(char *str, char c)
{
	size_t i;
	int q;

	i = 0;
	q = 0;
	if (!str || !c)
		return (-1);
	while (i < ft_strlen(str))
	{
		if (str[i] == c)
			q += 1;
		i += 1;
	}
	return (q);
}
