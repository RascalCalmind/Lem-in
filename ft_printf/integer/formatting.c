/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   formatting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 15:05:00 by mmarcell      #+#    #+#                 */
/*   Updated: 2019/07/15 14:08:08 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** -------------------------------------------------------------------------- **
** pushes the sign of the integer to the buffer
**
** params
**	int				is_positive	indicator whether the integer is positive
**	unsigned int	nbrlen		the length of the absolute integer according to
**								the given base
**	t_flags			*flags		pointer of struct with the flags for current
**								conversion
**	t_buffer		*buf		addres of the struct holding all info for the
**								buffer
** return
**	VOID
*/

void	print_number_sign(int is_positive, t_flags *flags, t_buffer *buf)
{
	if (flags->is_signed && !is_positive)
		buff_push(buf, "-", 1);
	if (flags->is_signed && is_positive && flags->pls)
		buff_push(buf, "+", 1);
}

/*
** -------------------------------------------------------------------------- **
** pushes all formatting characters that come before the actual integer
**
** params
**	int				is_positive	indicator whether the integer is positive
**	unsigned int	nbrlen		the length of the absolute integer according to
**								the given base
**	t_flags			*flags		address of struct with the flags for current
**								conversion
**	t_buffer		*buf		addres of the struct holding all info for the
**								buffer
** return
**	VOID
*/

void	format_prepend(int is_positive, unsigned int nbrlen,\
		t_flags *flags, t_buffer *buf)
{
	if (flags->hsh && (flags->base == 8 || flags->base == 16))
		nbrlen = flags->base == 8 ? nbrlen + 1 : nbrlen + 2;
	if (flags->base == 16 && flags->hsh && (!flags->pdn || flags->zr)
			&& is_positive)
		buff_push(buf, flags->is_cap ? "0X" : "0x", 2);
	if (nbrlen < flags->pdn && !flags->mns)
	{
		if (flags->zr && !flags->hsh)
			buff_filler(buf, '0', flags->pdn - nbrlen);
		if (!flags->zr && flags->pdn > (nbrlen + flags->prcs))
			buff_filler(buf, ' ', flags->pdn - nbrlen - flags->prcs);
		if (flags->hsh && flags->zr)
			buff_filler(buf, '0', flags->pdn - nbrlen);
		if (flags->base == 10 && !flags->zr)
			print_number_sign(is_positive, flags, buf);
	}
	if (flags->base == 16 && flags->hsh && (flags->pdn && !flags->zr))
		buff_push(buf, flags->is_cap ? "0X" : "0x", 2);
	if (flags->prcs)
		buff_filler(buf, '0', flags->prcs);
	if (flags->base == 8 && flags->hsh)
		buff_push(buf, "0", 1);
}

/*
** -------------------------------------------------------------------------- **
** pushes all formatting characters that come after the actual integer
**
** params
**	unsigned int	nbrlen	the length of the absolute integer according to the
**							given base
**	t_flags			*flags	pointer of struct with the flags for current
**							conversion
**	t_buffer		*buf	addres of the struct holding all info for the buffer
** return
**	VOID
*/

void	format_append(unsigned int nbrlen, t_flags *flags, t_buffer *buf)
{
	if (flags->hsh && (flags->base == 8 || flags->base == 16))
		nbrlen = flags->base == 8 ? nbrlen + 1 : nbrlen + 2;
	if (flags->mns && flags->dt)
	{
		if ((flags->base == 10 || flags->base == 8)
				&& (flags->pdn > (flags->prcs + nbrlen)))
			buff_filler(buf, ' ', flags->pdn - (flags->prcs + nbrlen));
		else if (flags->pdn > (flags->prcs + nbrlen))
			buff_filler(buf, ' ', flags->pdn - (flags->prcs + nbrlen));
	}
	else if (flags->mns && nbrlen < flags->pdn)
		buff_filler(buf, ' ', flags->pdn - nbrlen);
}
