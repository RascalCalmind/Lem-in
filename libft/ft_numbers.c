/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numbers.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/07 17:10:42 by mvan-hou       #+#    #+#                */
/*   Updated: 2019/09/20 16:38:05 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			ft_int_length(t_list *list, long long num)
{
	if (HH_SET)
		return ((char)num);
	if (H_SET)
		return ((short)num);
	if (LONG_SET)
		return ((long)num);
	if (LL_SET)
		return (num);
	return ((int)num);
}

unsigned long long	ft_oux_length(t_list *list, unsigned long long num)
{
	if (HH_SET)
		return ((unsigned char)num);
	if (H_SET)
		return ((unsigned short)num);
	if (LONG_SET)
		return ((unsigned long)num);
	if (LL_SET)
		return (num);
	return ((unsigned int)num);
}

t_num				ft_create_num(t_list *list, unsigned long long n, int base)
{
	t_num	nbr;

	nbr.value = n;
	nbr.base = base;
	nbr.size = ft_getsize(n, base);
	if (PRECISION_SET && list->precision == 0 && nbr.value == 0)
		nbr.size = 0;
	return (nbr);
}
