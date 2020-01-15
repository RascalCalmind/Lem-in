/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_float.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 14:41:40 by mvan-hou       #+#    #+#                */
/*   Updated: 2019/09/22 19:45:16 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ftoa_base(t_list *list, t_buf *buf, long long n, int base)
{
	t_num	nbr;

	if (n < 0)
	{
		ft_string_to_buf(buf, "ERROR", 5);
		return ;
	}
	nbr.value = n;
	nbr.base = base;
	nbr.size = ft_getsize(n, base);
	if (list->sign == -1 || PLUS_SET)
		list->flags &= ~(FLAG_SPACE);
	if (ZERO_SET && !(MINUS_SET) && (list->sign == -1 || PLUS_SET))
		ft_print_sign(list, buf);
	if (MINFW_SET && !(MINUS_SET) && list->minfw > (nbr.size + list->precision)
	&& !(BIG_F_SET))
		ft_print_width(list, buf, (nbr.size + list->precision));
	else if (SPACE_SET)
	{
		list->flags &= ~(FLAG_SPACE);
		ft_put_to_buf(buf, ' ');
	}
	ft_itoa_base(list, buf, nbr);
}

void	ft_print_front(t_list *list, t_buf *buf, long long integer)
{
	if (!PRECISION_ZERO || HASH_SET)
	{
		list->precision++;
		ft_ftoa_base(list, buf, integer, 10);
		ft_put_to_buf(buf, '.');
	}
	else
		ft_ftoa_base(list, buf, integer, 10);
}

void	ft_print_decimal(t_list *list, t_buf *buf, long long decimals)
{
	int size;

	size = list->precision;
	while (size - ft_getsize(decimals, 10) > 1)
	{
		size--;
		ft_put_to_buf(buf, '0');
	}
	if (list->precision > 0)
		ft_ftoa_base(list, buf, decimals, 10);
}

void	ft_print_float(t_list *list, t_buf *buf, long double flo, long long in)
{
	int			prec;
	long long	size;
	long long	decimals;
	int			rnd;

	prec = list->precision;
	size = ft_minimum(prec, 1);
	while (prec >= 1)
	{
		prec--;
		flo *= 10;
	}
	decimals = (long long)flo;
	rnd = (int)((flo - (long long)flo) * 100);
	ft_round(&in, &decimals, rnd, list->precision);
	if (ft_getsize(decimals, 10) > size)
	{
		in += 1;
		decimals = 0;
	}
	ft_print_front(list, buf, in);
	ft_print_decimal(list, buf, decimals);
}

void	ft_float(t_list *list, t_buf *buf, long double num)
{
	int			prec;
	int			size;
	long long	integer;

	prec = list->precision;
	if (ft_inf_nan(list, buf, num) == 1)
		return ;
	size = ft_getsize((long long)num, 10);
	if (num >= 9223372036854775807.0)
		ft_massive_floats(list, buf, ft_abs_float(num), prec);
	else
	{
		integer = (long long)num;
		num = num - (long long)num;
		if (prec < 19)
			ft_print_float(list, buf, num, integer);
		else
			ft_high_precision(list, buf, integer, num);
		if (MINFW_SET && MINUS_SET)
			ft_print_width(list, buf, (size + list->precision));
	}
}
