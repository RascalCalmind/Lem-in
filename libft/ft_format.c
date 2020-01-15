/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_format.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 16:50:27 by mvan-hou       #+#    #+#                */
/*   Updated: 2019/09/22 18:49:37 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isformat(char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' \
	|| c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f' || c == 'b'
	|| c == 'k')
		return (1);
	return (0);
}

int		ft_isflagchar(char c)
{
	if (c == '+' || c == '-' || c == '#' || c == '0' || c == ' ')
		return (1);
	if (c == 'l' || c == 'L' || c == 'h')
		return (2);
	return (0);
}

size_t	ft_format_length(const char *format)
{
	size_t	len;

	len = 0;
	while (*format && *format != '%')
	{
		format++;
		len++;
	}
	if (len < 1)
		return (1);
	return (len);
}

int		ft_formatcheck(const char *format, int i, t_list *list)
{
	const char	*str;
	int			j;

	str = format + i;
	j = 0;
	while (format[i] && ft_isformat(format[i]) != 1)
	{
		j++;
		i++;
	}
	if (ft_isformat(format[i]) != 1)
		return (-1);
	if (ft_order(str) != 0)
		return (-1);
	ft_flags(str, list);
	if (ft_isformat(str[j]) == 1)
		list->argtype = str[j];
	return (j + 1);
}
