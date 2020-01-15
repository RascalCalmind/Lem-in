/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 08:04:56 by lhageman      #+#    #+#                 */
/*   Updated: 2019/01/18 08:05:38 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int *mem;

	mem = (void *)malloc(size);
	if (mem == NULL)
	{
		return (0);
	}
	if (mem)
	{
		ft_bzero(mem, size);
		return (mem);
	}
	return (0);
}
