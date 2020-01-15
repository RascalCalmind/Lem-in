/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 00:09:39 by mvan-hou       #+#    #+#                */
/*   Updated: 2019/09/19 14:49:58 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_left_aligned(t_list *list, t_buf *buf, t_num nbr)
{
	if (HASH_SET)
	{
		if (list->capital == 1)
			ft_string_to_buf(buf, "0X", 2);
		else
			ft_string_to_buf(buf, "0x", 2);
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

void		ft_right_aligned(t_list *list, t_buf *buf, t_num nbr)
{
	if (MINFW_SET)
	{
		if (ZERO_SET && (list->sign == -1 || PLUS_SET))
			ft_print_sign(list, buf);
		ft_print_width(list, buf, nbr.size);
	}
	if (HASH_SET)
	{
		if (list->capital == 1)
			ft_string_to_buf(buf, "0X", 2);
		else
			ft_string_to_buf(buf, "0x", 2);
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
}

void		ft_pretoa_base(t_list *list, t_buf *buf, unsigned long long n,
			int base)
{
	t_num	nbr;

	nbr = ft_create_num(list, n, base);
	if (HASH_SET)
		list->precision -= 2;
	if (PRECISION_SET)
	{
		list->flags &= ~(FLAG_ZERO);
		list->minfw = list->minfw - ft_minimum(list->precision - nbr.size, 0);
	}
	if (list->sign == -1 || PLUS_SET)
		list->flags &= ~(FLAG_SPACE);
	if (SPACE_SET && !(PLUS_SET || list->sign == -1))
	{
		ft_put_to_buf(buf, ' ');
		list->minfw--;
	}
	if (MINUS_SET)
		ft_left_aligned(list, buf, nbr);
	else
		ft_right_aligned(list, buf, nbr);
}

char		*ft_baseline(t_list *list)
{
	if (list->capital == 1)
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

void		ft_itoa_base(t_list *list, t_buf *buf, t_num n)
{
	char				str[21];
	char				*ascii;
	unsigned long long	nbr;
	int					i;

	nbr = n.value;
	i = n.size - 1;
	ascii = ft_baseline(list);
	if (((PLUS_SET || list->sign == -1) &&
	(!(ZERO_SET) || (MINUS_SET))) && list->sign != 0)
		ft_print_sign(list, buf);
	if (nbr == 0 && (list->precision > 1 || (PRECISION_ZERO &&
	(HASH_SET) && list->argtype == 'o')))
	{
		ft_put_to_buf(buf, '0');
		return ;
	}
	while (i >= 0)
	{
		str[i] = ascii[nbr % n.base];
		nbr /= n.base;
		i--;
	}
	ft_number_to_buf(buf, str, n.value, n.size);
}
