/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_test.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/23 18:11:27 by mvan-hou       #+#    #+#                */
/*   Updated: 2019/08/23 18:11:51 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_binary(__uint16_t flag_num)
{
	int				bit;
	int				pos;

	pos = 16;
	ft_putstr("\n the num is :");
	ft_putnbr(flag_num);
	ft_putchar('\n');
	while (pos >= 0)
	{
		bit = flag_num >> pos;
		if (bit & 1)
			ft_putstr("1 ");
		else
			ft_putstr("0 ");
		pos--;
	}
	ft_putchar('\n');
}

void			print_float(void *flo)
{
	int				bit;
	int				pos;
	unsigned char	*data;

	data = flo;
	pos = 64;
	ft_putstr("the float is:[");
	while (pos >= 0)
	{
		bit = *data >> pos;
		if (bit & 1)
			ft_putchar('1');
		else
			ft_putchar('0');
		pos--;
	}
	ft_putstr("]\n\n");
}
