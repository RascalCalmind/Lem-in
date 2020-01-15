/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_flags.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 19:43:15 by lhageman       #+#    #+#                */
/*   Updated: 2019/09/23 19:35:42 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_length(const char *format, t_list *list, int i)
{
	i = 0;
	while (ft_isflagchar(format[i]) >= 1)
	{
		if (format[i] == 'h')
			if (format[i + 1] == 'h')
			{
				list->flags |= FLAG_HH;
				i++;
			}
			else
				list->flags |= FLAG_H;
		else if (format[i] == 'l')
			if (format[i + 1] == 'l')
			{
				list->flags |= FLAG_LL;
				i++;
			}
			else
				list->flags |= FLAG_LONG;
		else if (format[i] == 'L')
			list->flags |= FLAG_LD;
		i++;
	}
	return (i);
}

int		ft_precision(const char *format, t_list *list)
{
	if (*format == '.' && *(format + 1) != '*')
	{
		list->flags |= FLAG_PRECISION;
		list->precision = ft_atoi(format + 1);
		if (!ft_isdigit(*(format + 1)))
			return (1);
		return (ft_getsize(list->precision, 10) + 1);
	}
	else if (*format == '.' && *(format + 1) == '*')
	{
		list->flags |= FLAG_PRECISION;
		list->precision = va_arg(list->varg, int);
		if (list->precision < 0)
		{
			list->flags &= ~(FLAG_PRECISION);
			list->precision = 0;
		}
		return (2);
	}
	return (0);
}

int		ft_set_flags(const char *format, t_list *list)
{
	int i;

	i = 0;
	while (ft_isflagchar(format[i]) == 1)
	{
		if (format[i] == '-')
			list->flags |= FLAG_MINUS;
		else if (format[i] == '+')
			list->flags |= FLAG_PLUS;
		else if (format[i] == ' ')
			list->flags |= FLAG_SPACE;
		else if (format[i] == '#')
			list->flags |= FLAG_HASH;
		else if (format[i] == '0')
			list->flags |= FLAG_ZERO;
		i++;
	}
	return (i);
}

int		ft_width(const char *format, t_list *list)
{
	if (ft_isdigit(*format))
	{
		list->flags |= FLAG_MINFW;
		list->minfw = ft_atoi(format);
		return (ft_getsize(list->minfw, 10));
	}
	else if (*format == '*')
	{
		list->flags |= FLAG_MINFW;
		list->minfw = va_arg(list->varg, int);
		if (list->minfw < 0)
		{
			list->minfw *= -1;
			list->flags |= FLAG_MINUS;
		}
		if (ft_isdigit(*(format + 1)))
		{
			list->flags |= FLAG_MINFW;
			list->minfw = ft_atoi(format + 1);
			return (ft_getsize(list->minfw, 10));
		}
		return (1);
	}
	return (0);
}

int		ft_flags(const char *format, t_list *list)
{
	format += ft_set_flags(format, list);
	format += ft_width(format, list);
	format += ft_precision(format, list);
	format += ft_length(format, list, 0);
	return (0);
}
