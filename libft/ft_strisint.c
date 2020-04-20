/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strisint.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 18:40:27 by lhageman      #+#    #+#                 */
/*   Updated: 2020/04/20 15:25:35 by wmisiedjan    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_int(char *str)
{
	int i;
	int s;
	int	r;

	r = 0;
	i = 0;
	s = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	if (!(str[0] >= '0' && str[0] <= '9'))
	{
		return (-1);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (r > 214748364 || r < -214748364 || (r == 214748364 &&\
		((str[i] == '8' && s != -1) || (str[i + 1] >= '0' &&\
		str[i + 1] >= '9') || (str[i] > '8'))))
			return (-1);
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (0);
}
