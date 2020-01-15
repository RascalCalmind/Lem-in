/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 10:15:02 by lhageman      #+#    #+#                 */
/*   Updated: 2019/01/16 10:15:06 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char			*csrc;
	char			*cdst;

	cdst = (char *)dst;
	csrc = (char *)src;
	if (n == 0)
		return (dst);
	while (--n)
	{
		*cdst++ = *csrc++;
	}
	*cdst = *csrc;
	return (dst);
}
