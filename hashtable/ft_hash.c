/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashf.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 14:50:43 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/29 19:22:11 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// TODO: Fix comment
/**
 * Hashing algorithm based on SDBM.
 * 
 * Code: hash(i) = hash(i - 1) * 65599 + str[i];
 * 
 * @ref: http://www.cse.yorku.ca/~oz/hash.html
 */

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
