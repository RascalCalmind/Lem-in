/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 17:25:12 by wmisiedj      #+#    #+#                 */
/*   Updated: 2019/06/27 18:35:18 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_atoi(const char *s)
{
	unsigned int		result;
	int					sign;
	size_t				i;

	sign = 1;
	result = 0;
	i = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\r' || s[i] == '\v' ||
		s[i] == '\f' || s[i] == ' ')
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] && '0' <= s[i] && s[i] <= '9')
	{
		result = s[i] - '0' + result * 10;
		i++;
	}
	return (sign * result);
}
