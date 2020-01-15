/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_order.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/11 14:57:14 by lhageman       #+#    #+#                */
/*   Updated: 2019/09/21 17:22:36 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_startminfw(const char *str, int i)
{
	while (ft_isdigit(str[i]) == 1 || str[i] == '*')
		i++;
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]) == 1 || str[i] == '*')
		i++;
	while (ft_isflagchar(str[i]) == 2 || ft_isspace(str[i]) == 1)
		i++;
	if (ft_isformat(str[i]) == 1)
		return (0);
	return (-1);
}

int		ft_startprec(const char *str, int i)
{
	i++;
	while (ft_isdigit(str[i]) == 1 || str[i] == '*')
		i++;
	while (ft_isflagchar(str[i]) == 2 || ft_isspace(str[i]) == 1)
		i++;
	if (ft_isformat(str[i]) == 1)
		return (0);
	return (-1);
}

int		ft_startflag(const char *str, int i)
{
	i++;
	while (ft_isflagchar(str[i]) == 1)
		i++;
	if (ft_startminfw(str, i) == 0)
		return (0);
	return (-1);
}

int		ft_startprecormod(const char *str, int i)
{
	if (str[i] == '.')
	{
		if (ft_startprec(str, i) == 0)
			return (0);
		return (-1);
	}
	else if (ft_isflagchar(str[i]) == 2)
	{
		while (ft_isflagchar(str[i]) == 2 || ft_isspace(str[i]) == 1)
			i++;
		if (ft_isformat(str[i]) == 1)
			return (0);
		return (-1);
	}
	return (-1);
}

int		ft_order(const char *str)
{
	int i;

	i = 0;
	while (ft_isformat(str[i]) != 1 && str[i])
	{
		if (ft_isflagchar(str[i]) == 1)
			if (ft_startflag(str, i) == 0)
				return (0);
			else
				return (-1);
		else if (ft_isdigit(str[i]) == 1 || str[i] == '*')
			if (ft_startminfw(str, i) == 0)
				return (0);
			else
				return (-1);
		else if (str[i] == '.' || ft_isflagchar(str[i]) == 1)
			if (ft_startprecormod(str, i) == 0)
				return (0);
			else
				return (-1);
		else if (ft_isformat(str[i]) == 1)
			return (0);
		i++;
	}
	return (0);
}
