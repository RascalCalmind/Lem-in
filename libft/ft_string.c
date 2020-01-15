/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_string.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 15:46:51 by lhageman       #+#    #+#                */
/*   Updated: 2019/09/19 14:49:58 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string(t_list *list, t_buf *buf, char *str)
{
	int prec;
	int len;

	prec = 0;
	len = ft_strlen(str);
	if (PRECISION_SET && list->precision < len)
		len = list->precision;
	if (MINFW_SET && !(MINUS_SET))
		ft_print_width(list, buf, len);
	while (*str)
	{
		if (PRECISION_SET && prec < list->precision)
		{
			ft_put_to_buf(buf, *str);
			prec++;
		}
		else if (!(PRECISION_SET))
			ft_put_to_buf(buf, *str);
		str++;
	}
	if (MINFW_SET && MINUS_SET)
		ft_print_width(list, buf, len);
}

void	ft_char(t_list *list, t_buf *buf, char c)
{
	if (SPACE_SET && MINUS_SET)
		list->minfw++;
	if (MINFW_SET && !(MINUS_SET))
		ft_print_width(list, buf, 1);
	ft_put_to_buf(buf, c);
	if (MINFW_SET && MINUS_SET)
		ft_print_width(list, buf, 1);
}
