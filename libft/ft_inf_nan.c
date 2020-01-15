/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_inf_nan.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 15:22:23 by mvan-hou       #+#    #+#                */
/*   Updated: 2019/09/19 14:49:58 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_inf(t_list *list, t_buf *buf)
{
	if (list->sign == -1)
	{
		ft_string_to_buf(buf, "-inf", 4);
		return ;
	}
	if (SPACE_SET && list->minfw <= 3)
		ft_put_to_buf(buf, ' ');
	ft_string_to_buf(buf, "inf", 3);
}

int		ft_inf_nan(t_list *list, t_buf *buf, long double num)
{
	if (num != num || num == 1.0 / 0.0)
	{
		list->flags &= ~(FLAG_ZERO);
		if (MINUS_SET || !(MINFW_SET))
		{
			if (num != num)
				ft_string_to_buf(buf, "nan", 3);
			if (num == 1.0 / 0.0 || num == 1.0 / 0.0)
				ft_print_inf(list, buf);
			if (MINFW_SET)
				ft_print_width(list, buf, 3);
		}
		else if (MINFW_SET)
		{
			ft_print_width(list, buf, 3);
			if (num != num)
				ft_string_to_buf(buf, "nan", 3);
			if (num == 1.0 / 0.0 || num == -1.0 / 0.0)
				ft_print_inf(list, buf);
		}
		return (1);
	}
	return (0);
}
