/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_binary.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 16:16:45 by mvan-hou       #+#    #+#                */
/*   Updated: 2019/09/25 15:11:18 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_binary_max_size(t_list *list)
{
	if (HH_SET)
		return (7);
	if (H_SET)
		return (15);
	if (LONG_SET)
		return (63);
	if (LL_SET)
		return (127);
	return (31);
}

int		ft_binary_size(t_list *list, unsigned long long num)
{
	int i;

	i = ft_binary_max_size(list);
	while (!(HASH_SET))
	{
		if (!(num & (1 << i)) && i > 0)
			i--;
		else
			return (i);
	}
	return (i);
}

int		ft_binary_width(t_list *list, int size)
{
	if (HASH_SET)
		return (size + ((size + 1) / 4));
	return (size + 1);
}

void	ft_btoa(t_list *list, t_buf *buf, unsigned long long num, int size)
{
	int i;

	i = size;
	if (MINFW_SET && !(MINUS_SET))
		ft_print_width(list, buf, ft_binary_width(list, size));
	while (i >= 0)
	{
		if (HASH_SET && (i + 1) % 4 == 0 && i != size)
			ft_put_to_buf(buf, ' ');
		if (num & (1 << i))
			ft_put_to_buf(buf, '1');
		else
			ft_put_to_buf(buf, '0');
		i--;
	}
	if (MINFW_SET && (MINUS_SET))
		ft_print_width(list, buf, ft_binary_width(list, size));
}
