/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hash.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 14:50:43 by lhageman      #+#    #+#                 */
/*   Updated: 2020/03/11 17:44:55 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_hash_sdbm(char *str, unsigned int max_int)
{
	int				i;
	unsigned long	hash;

	i = 0;
	hash = 0;
	while (str[i])
	{
		hash = str[i] + (hash << 6) + (hash << 16) - hash;
		i++;
	}
	hash %= max_int;
	return (hash);
}
