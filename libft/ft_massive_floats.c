/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_massive_floats.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 15:03:49 by mvan-hou       #+#    #+#                */
/*   Updated: 2019/09/22 19:49:32 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_high_precision(t_list *list, t_buf *buf, long long in,
		long double flo)
{
	int prec;

	ft_print_front(list, buf, in);
	prec = list->precision;
	while (prec > 2)
	{
		flo *= 10;
		ft_put_to_buf(buf, (char)flo + '0');
		flo = flo - (long long)flo;
		prec--;
	}
	flo *= 10;
	if ((int)((flo - (int)flo) * 10) > 5 && (int)flo < 9)
		ft_put_to_buf(buf, (char)flo + '1');
	else
		ft_put_to_buf(buf, (char)flo + '0');
}

void	ft_massive_remainder(t_buf *buf, long double num, int counter)
{
	while (counter > 1)
	{
		num *= 10;
		ft_put_to_buf(buf, (int)num + '0');
		num = num - (int)num;
		counter--;
	}
}

void	ft_massive_decimal(t_list *list, t_buf *buf, int prec)
{
	if (list->precision > 0 || HASH_SET)
		ft_put_to_buf(buf, '.');
	while (prec > 0)
	{
		ft_put_to_buf(buf, '0');
		prec--;
	}
}

void	ft_massive_floats(t_list *list, t_buf *buf, long double num, int prec)
{
	int				counter;
	int				size;

	counter = 1;
	list->flags |= BIG_F;
	if (PRECISION_ZERO && !(HASH_SET))
		list->precision--;
	while (num >= 9223372036854775807.0)
	{
		num /= 10;
		counter++;
	}
	size = ft_getsize((long long)num, 10) + counter;
	if (MINFW_SET && !(MINUS_SET))
		ft_print_width(list, buf, (size + list->precision));
	ft_ftoa_base(list, buf, (long long)num, 10);
	if (list->sign == -1 || PLUS_SET)
		ft_print_sign(list, buf);
	ft_massive_remainder(buf, num, counter);
	ft_massive_decimal(list, buf, prec);
	if (MINFW_SET && MINUS_SET)
		ft_print_width(list, buf, (size + list->precision));
}
