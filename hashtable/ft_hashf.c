/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashf.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 14:50:43 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/29 15:42:10 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

// TODO: Make smaller (26 lines)
int	ft_hashf(char *name)
{
	int				i;
	char			*str;
	unsigned long	hash;
	int				c;
	int				num;

	i = 0;
	c = 0;
	hash = 5381;
	if (!name)
		return (-1);
	while (name[i]++) // NOT ALLOWED TO ++ into thingy
	{
		c = name[i];
		hash = ((hash << 5) + hash) + c;
	}
	str = ft_itoa(hash);
	if (!str)
		return (-1);
	str = ft_strsub(str, 5, 4);
	if (!str)
		return (-1);
	num = atoi(str);
	if (str)
		free(str);
	return (num);
}
