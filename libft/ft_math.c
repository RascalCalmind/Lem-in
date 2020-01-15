/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_math.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/23 16:46:26 by lhageman       #+#    #+#                */
/*   Updated: 2019/09/25 15:13:09 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_round(long long *in, long long *dec, int rnd, int prec)
{
	if (rnd > 56 || (rnd >= 49 && (*in % 2 != 0)))
	{
		if (prec == 0)
			*in += 1;
		else
			*dec += 1;
	}
}

int			ft_getsize(unsigned long long n, unsigned int base)
{
	int		size;

	size = 1;
	while (n >= base)
	{
		n /= base;
		size++;
	}
	return (size);
}

long long	ft_minimum(long long nbr, long long minimum)
{
	if (nbr < minimum)
		return (minimum);
	return (nbr);
}

long long	ft_abs(long long nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

long double	ft_abs_float(long double nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}
