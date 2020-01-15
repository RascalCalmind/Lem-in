/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_width.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 21:10:19 by mvan-hou       #+#    #+#                */
/*   Updated: 2019/09/21 15:50:35 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_sign(t_list *list, t_buf *buf)
{
	if (list->sign == 1)
		ft_put_to_buf(buf, '+');
	else if (list->sign == -1)
		ft_put_to_buf(buf, '-');
	list->sign = 0;
}

char	ft_padding_char(t_list *list)
{
	if (ZERO_SET && !(MINUS_SET))
		return ('0');
	return (' ');
}

void	ft_int_precision(t_list *list, t_buf *buf, int size)
{
	int		prec;

	prec = list->precision - size;
	if (size == 0)
		prec--;
	while (prec > 0)
	{
		ft_put_to_buf(buf, '0');
		prec--;
	}
}

void	ft_print_width(t_list *list, t_buf *buf, int size)
{
	int		width;
	char	pad;

	pad = ft_padding_char(list);
	width = list->minfw - size;
	if (list->sign < 1 || PLUS_SET)
		width--;
	while (width > 0)
	{
		ft_put_to_buf(buf, pad);
		width--;
	}
	list->minfw = 0;
}
