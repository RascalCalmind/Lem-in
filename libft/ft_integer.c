/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_integer.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/01 17:30:21 by lhageman       #+#    #+#                */
/*   Updated: 2019/09/07 16:36:38 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_integer(t_list *list, t_buf *buf, long long dble)
{
	ft_pretoa_base(list, buf, ft_abs(dble), 10);
}
