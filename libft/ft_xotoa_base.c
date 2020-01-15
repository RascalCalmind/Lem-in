/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_xotoa_base.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/03 21:38:34 by mvan-hou       #+#    #+#                */
/*   Updated: 2019/09/18 15:13:33 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_left_aligned(t_list *list, t_buf *buf, t_num nbr)
{
	list->flags &= ~(FLAG_ZERO);
	if (HASH_SET)
	{
		if (list->capital == 1 && list->argtype != 'o' && nbr.value != 0)
			ft_string_to_buf(buf, "0X", 2);
		else if ((list->argtype != 'o' && nbr.value != 0) || list->argtype
		== 'p')
			ft_string_to_buf(buf, "0x", 2);
		else if (list->argtype == 'o' && nbr.value != 0)
			ft_put_to_buf(buf, '0');
	}
	if (PRECISION_SET)
	{
		if (list->sign == -1 || PLUS_SET)
			ft_print_sign(list, buf);
		ft_int_precision(list, buf, nbr.size);
	}
	else if (list->sign == -1 || PLUS_SET)
		ft_print_sign(list, buf);
	ft_itoa_base(list, buf, nbr);
	if (MINFW_SET)
		ft_print_width(list, buf, nbr.size);
}

static void		ft_right_aligned(t_list *list, t_buf *buf, t_num nbr)
{
	if (MINFW_SET)
		ft_print_width(list, buf, nbr.size);
	if (HASH_SET)
	{
		if (list->capital == 1 && list->argtype != 'o' && nbr.value != 0)
			ft_string_to_buf(buf, "0X", 2);
		else if ((list->argtype != 'o' && nbr.value != 0) ||
		list->argtype == 'p')
			ft_string_to_buf(buf, "0x", 2);
		else if (list->argtype == 'o' && nbr.value != 0)
			ft_put_to_buf(buf, '0');
	}
	if (PRECISION_SET)
		ft_int_precision(list, buf, nbr.size);
	ft_itoa_base(list, buf, nbr);
}

void			ft_set_swap(t_list *list)
{
	list->flags &= ~(FLAG_ZERO);
	list->flags |= (FLAG_PRECISION);
	list->flags &= ~(FLAG_MINFW);
	list->precision = list->minfw;
	list->minfw = 0;
}

void			ft_hash(t_list *list, t_num nbr)
{
	if (((list->argtype == 'x' || list->argtype == 'X')
	&& nbr.value != 0) || list->argtype == 'p')
		list->minfw -= 2;
	if (list->argtype == 'o' && !(nbr.value == 0 &&
	PRECISION_ZERO) && !(HASH_SET))
		list->minfw += 1;
	if (list->argtype == 'o' && (nbr.value == 0 &&
	(PRECISION_ZERO || !(HASH_SET))))
	{
		if (PRECISION_ZERO && !(HASH_SET))
			list->minfw += 1;
		list->minfw -= 1;
	}
	if (list->argtype == 'o' && (nbr.value != 0 && HASH_SET))
	{
		list->precision -= 1;
		list->minfw -= 1;
	}
}

void			ft_xotoa_base(t_list *list, t_buf *buf, \
unsigned long long n, int base)
{
	t_num	nbr;

	nbr = ft_create_num(list, n, base);
	if (HASH_SET || nbr.value == 0)
		ft_hash(list, nbr);
	if (ZERO_SET && MINFW_SET && !(PRECISION_SET) && !(MINUS_SET))
		ft_set_swap(list);
	if (PRECISION_SET)
	{
		list->flags &= ~(FLAG_ZERO);
		list->minfw = list->minfw - ft_minimum(list->precision - nbr.size, 0);
	}
	if (list->sign == -1 || PLUS_SET)
		list->flags &= ~(SPACE_SET);
	if (SPACE_SET)
	{
		ft_put_to_buf(buf, ' ');
		list->minfw--;
	}
	if (MINUS_SET)
		ft_left_aligned(list, buf, nbr);
	else
		ft_right_aligned(list, buf, nbr);
}
