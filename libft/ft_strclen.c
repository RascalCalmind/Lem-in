/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strclen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/26 15:36:43 by lhageman      #+#    #+#                 */
/*   Updated: 2019/02/26 15:36:44 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(const char *s, int c)
{
	int i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0' && s[i] != (char)c)
		i++;
	return (i);
}
