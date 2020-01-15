/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_time.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/22 15:38:16 by mvan-hou       #+#    #+#                */
/*   Updated: 2019/09/22 19:18:45 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_calculate_year(int epoch, t_time *time)
{
	while (epoch >= 31622400)
	{
		if (time->year % 4 == 0)
			epoch -= 31622400;
		else
			epoch -= 31536000;
		time->year++;
	}
	return (epoch);
}

int		ft_calculate_month(int epoch, t_time *time)
{
	while (epoch >= 2628288)
	{
		epoch -= 86400 * ft_month(time->month, time->year);
		if (time->month == 12)
		{
			time->month = 1;
			time->year++;
		}
		time->month++;
	}
	return (epoch);
}

int		ft_calculate_day(int epoch, t_time *time)
{
	while (epoch >= 86400)
	{
		epoch -= 86400;
		time->day++;
	}
	return (epoch);
}

int		ft_calculate_time(int epoch, t_time *time)
{
	while (epoch >= 3600)
	{
		epoch -= 3600;
		time->hour++;
	}
	while (epoch >= 60)
	{
		epoch -= 60;
		time->minute++;
	}
	return (epoch);
}

void	ft_time(int epoch, t_list *list, t_buf *buf)
{
	char	*str;
	t_time	time;

	epoch += 7200;
	ft_set_list_time(&time);
	epoch = ft_calculate_year(epoch, &time);
	epoch = ft_calculate_month(epoch, &time);
	epoch = ft_calculate_day(epoch, &time);
	epoch = ft_calculate_time(epoch, &time);
	str = ft_time_string(time);
	if (str == NULL)
		return ;
	ft_string(list, buf, str);
	free(str);
}
