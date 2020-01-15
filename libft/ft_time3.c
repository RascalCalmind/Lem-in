/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_time3.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/22 19:13:39 by mvan-hou       #+#    #+#                */
/*   Updated: 2019/09/22 19:13:55 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minute_to_string(int minute, char *str)
{
	if (minute < 1)
	{
		str[14] = '0';
		str[15] = '0';
	}
	if (minute < 10)
	{
		str[14] = '0';
		str[15] = '0' + minute;
	}
	else
	{
		str[14] = minute / 10 + '0';
		str[15] = minute % 10 + '0';
	}
}

void	ft_hour_to_string(int hour, char *str)
{
	if (hour < 1)
	{
		str[11] = '0';
		str[12] = '0';
	}
	if (hour < 10)
	{
		str[11] = '0';
		str[12] = '0' + hour;
	}
	else
	{
		str[11] = hour / 10 + '0';
		str[12] = hour % 10 + '0';
	}
}

void	ft_day_to_string(int day, char *str)
{
	if (day < 10)
	{
		str[8] = '0';
		str[9] = day + '0';
	}
	else
	{
		str[8] = day / 10 + '0';
		str[9] = day % 10 + '0';
	}
}

void	ft_month_to_string(int month, char *str)
{
	if (month < 10)
	{
		str[5] = '0';
		str[6] = month + '0';
	}
	else
	{
		str[5] = '1';
		str[6] = month - 10 + '0';
	}
}

void	ft_year_to_string(int year, char *str)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_itoa(year);
	while (i < 4)
	{
		str[i] = temp[i];
		i++;
	}
	free(temp);
}
