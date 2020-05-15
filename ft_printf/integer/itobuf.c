/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   itobuf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/05 17:11:28 by mmarcell      #+#    #+#                 */
/*   Updated: 2019/07/25 15:45:50 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** -------------------------------------------------------------------------- **
** pushes the absolute value of nb with the given base to the buffer
** if nb < 0 the sign is switched and the absolute value pushed to the buffer
**
** params
**	long long int	nb		number to be printed
**	unsigned int	base	the base according to which the number has to be
**							printed
**	t_buffer		*buf	address of the buffer struct
** return
**	VOID
*/

void	absolute_itobuf(long long nb, unsigned int base, t_buffer *buf,
		int is_cap)
{
	char	c;

	if (nb < 0)
	{
		unsigned_itobuf((-1) * nb, base, buf, is_cap);
		return ;
	}
	if (nb < base)
	{
		if (nb < 10)
			c = '0' + nb;
		else
			c = is_cap ? ('A' + (nb - 10)) : ('a' + (nb - 10));
		buff_push(buf, &c, 1);
		return ;
	}
	else
	{
		absolute_itobuf((nb / base), base, buf, is_cap);
		absolute_itobuf((nb % base), base, buf, is_cap);
	}
	return ;
}

/*
** -------------------------------------------------------------------------- **
** pushes the unsigned value of nb with the given base to the buffer
** if nb < 0 the overflow value is pushed to the buffer
**
** params
**	long long unsigned int	nb		number to be printed
**	unsigned int			base	the base according to which the number has
**									to be printed
**	t_buffer				*buf	address of the struct holding all info for
**									the buffer
**	int						is_cap	indicator for capitalized letters in base 16
** return
**	VOID
*/

void	unsigned_itobuf(long long unsigned nb, unsigned int base,
		t_buffer *buf, int is_cap)
{
	char	c;

	if (nb < base)
	{
		if (nb < 10)
			c = '0' + nb;
		else
			c = is_cap ? ('A' + (nb - 10)) : ('a' + (nb - 10));
		buff_push(buf, &c, 1);
		return ;
	}
	else
	{
		unsigned_itobuf((nb / base), base, buf, is_cap);
		unsigned_itobuf((nb % base), base, buf, is_cap);
	}
	return ;
}
