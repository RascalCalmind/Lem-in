/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 18:54:04 by lhageman      #+#    #+#                 */
/*   Updated: 2019/01/19 18:54:06 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	char		*str;

	i = 0;
	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while ((char)*s1)
	{
		str[i] = (char)*s1;
		i++;
		s1++;
	}
	while ((char)*s2)
	{
		str[i] = (char)*s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}
