/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ftobuf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 15:05:43 by wmisiedj      #+#    #+#                 */
/*   Updated: 2019/07/29 12:42:36 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** -------------------------------------------------------------------------- **
** returns the rounder for a given precision
**
** params
**	int		precision
** return
**	int		[the rounder]
**	0 		in case of error
*/

long double			rounder(int precision)
{
	unsigned long long	power;

	power = ft_power(10, precision);
	if (power == 0)
		return (0);
	return (0.5 / power);
}

/*
** -------------------------------------------------------------------------- **
** pushes the given float f with a given precision to the buffer
**
** params
**	long double		f		number to be pushed
**	unsigned int	prcs	the precision f needs to be printed with
**	t_buffer		*buf	addres of the struct holding all info for the buffer
** return
**	VOID
*/

void				ftobuf(long double f, unsigned int prcs, t_buffer *buf)
{
	long long	integral;

	if (f < 0)
		f = -f;
	f += rounder(prcs);
	integral = f;
	f -= integral;
	unsigned_itobuf(integral, 10, buf, 0);
	if (prcs > 0)
		buff_push(buf, ".", 1);
	while (prcs > 0)
	{
		f = f * 10;
		integral = f;
		f = f - integral;
		unsigned_itobuf(integral, 10, buf, 0);
		--prcs;
	}
}

/*
** -------------------------------------------------------------------------- **
** in case the float is bigger than can be represented in an unsigned long long
** this function prints divides by an exponent of ten, to get a number taht has
** the first few digits in common and then adds '0' until teh number to reresent
** and its representaion reach the same length
**
** params
**	long double		f		number to be pushed
**	unsigned int	prcs	the precision f needs to be printed with
**	t_buffer		*buf	addres of the struct holding all info for the buffer
**	unsigned int	len		the length of the number (the whole part of the
**							number, so not including a decimal point or
**							precision)
** return
**	VOID
*/

void				longftobuf(long double ldb, unsigned int prcs,
						unsigned int len, t_buffer *buf)
{
	ftobuf(ldb / ft_ldouble_power(10, len - (prcs + 1) - 19), 0, buf);
	buff_filler(buf, '0', len - (prcs + 1) - 19);
	buff_filler(buf, '.', 1);
	buff_filler(buf, '0', prcs);
}
