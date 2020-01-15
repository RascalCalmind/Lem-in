/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_perc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 19:47:35 by lhageman       #+#    #+#                */
/*   Updated: 2019/08/23 18:11:11 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find_conv_perc(const char *str, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			return (i);
		i += 1;
	}
	return (-1);
}
