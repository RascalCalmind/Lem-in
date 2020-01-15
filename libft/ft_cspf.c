/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cspf.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 15:28:13 by lhageman       #+#    #+#                */
/*   Updated: 2019/09/22 18:50:57 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_create_b(unsigned long long num, t_list *list, t_buf *buf)
{
	num = ft_oux_length(list, num);
	ft_btoa(list, buf, num, ft_binary_size(list, num));
}

void	ft_create_p(unsigned long long ptr, t_list *list, t_buf *buf)
{
	list->flags |= FLAG_HASH;
	ft_xotoa_base(list, buf, ptr, 16);
}

void	ft_create_f(long double flo, t_list *list, t_buf *buf)
{
	if (!(PRECISION_SET))
		list->precision = 6;
	if (flo < 0 || (1 / flo) == (1 / -0.0))
		list->sign = -1;
	ft_float(list, buf, ft_abs_float(flo));
}

void	ft_percent(t_list *list, t_buf *buf)
{
	unsigned long long	num;

	if (list->argtype == '%')
	{
		ft_char(list, buf, '%');
	}
	if (list->argtype == 'u')
	{
		num = va_arg(list->varg, unsigned long long);
		ft_create_u(num, list, buf);
	}
	if (list->argtype == 'b')
	{
		num = va_arg(list->varg, unsigned long long);
		ft_create_b(num, list, buf);
	}
	if (list->argtype == 'k')
	{
		list->flags &= ~(FLAG_PRECISION);
		ft_time(va_arg(list->varg, int), list, buf);
	}
}
