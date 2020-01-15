/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_time2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/22 19:11:19 by mvan-hou       #+#    #+#                */
/*   Updated: 2019/09/22 19:14:34 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_month(int month, int year)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
		|| month == 10 || month == 12)
		return (31);
	if (year % 4 == 0 && month == 2)
		return (29);
	if (month == 2)
		return (28);
	return (30);
}

char	*ft_time_string(t_time time)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * 17);
	if (!str)
		return (NULL);
	ft_year_to_string(time.year, str);
	str[4] = '-';
	ft_month_to_string(time.month, str);
	str[7] = '-';
	ft_day_to_string(time.day, str);
	str[10] = ' ';
	ft_hour_to_string(time.hour, str);
	str[13] = ':';
	ft_minute_to_string(time.minute, str);
	str[16] = '\0';
	return (str);
}

void	ft_set_list_time(t_time *time)
{
	time->year = 1970;
	time->month = 1;
	time->day = 1;
	time->hour = 0;
	time->minute = 0;
}
