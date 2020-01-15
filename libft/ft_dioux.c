/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dioux.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 15:25:33 by lhageman       #+#    #+#                */
/*   Updated: 2019/09/21 18:08:53 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_create_u(unsigned long long num, t_list *list, t_buf *buf)
{
	list->flags &= ~((FLAG_SPACE) + FLAG_PLUS);
	num = ft_oux_length(list, num);
	ft_pretoa_base(list, buf, num, 10);
}

void	ft_create_d(long long num, t_list *list, t_buf *buf)
{
	num = ft_int_length(list, num);
	if (num < 0)
		list->sign = -1;
	ft_integer(list, buf, num);
}

void	ft_integers(t_list *list, t_buf *buf)
{
	long long	num;

	if ((list->argtype == 'd' || list->argtype == 'i'))
	{
		num = va_arg(list->varg, long long);
		if (num < -9223372036854775807)
		{
			list->argtype = 'u';
			ft_create_u(num, list, buf);
		}
		else
			ft_create_d(num, list, buf);
	}
}

void	ft_nextnextformat(t_list *list, t_buf *buf)
{
	unsigned long long hex;

	if ((list->argtype == 'x' || list->argtype == 'X') && (LD_SET || LL_SET))
	{
		hex = va_arg(list->varg, unsigned long long);
		if (list->argtype == 'X')
			list->capital = 1;
		ft_xotoa_base(list, buf, ft_oux_length(list, hex), 16);
	}
	else if (list->argtype == 'x' || list->argtype == 'X')
	{
		hex = va_arg(list->varg, unsigned long long);
		if (list->argtype == 'X')
			list->capital = 1;
		ft_xotoa_base(list, buf, ft_oux_length(list, hex), 16);
	}
	else if (list->argtype == 'o')
	{
		hex = va_arg(list->varg, unsigned long long);
		ft_xotoa_base(list, buf, ft_oux_length(list, hex), 8);
	}
	else
		ft_percent(list, buf);
}

void	ft_nextformat(t_list *list, t_buf *buf)
{
	long double flo;
	double		flosmoll;

	if (list->argtype == 'f' && LD_SET)
	{
		flo = va_arg(list->varg, long double);
		ft_create_f(flo, list, buf);
		return ;
	}
	else if (list->argtype == 'f')
	{
		flosmoll = va_arg(list->varg, double);
		ft_create_f(flosmoll, list, buf);
		return ;
	}
	else if (list->argtype == 'd' || list->argtype == 'i')
		ft_integers(list, buf);
	else
		ft_nextnextformat(list, buf);
}
