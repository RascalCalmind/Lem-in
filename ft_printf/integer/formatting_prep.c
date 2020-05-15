/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   formatting_prep.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 15:03:36 by mmarcell      #+#    #+#                 */
/*   Updated: 2019/08/14 17:30:07 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** -------------------------------------------------------------------------- **
** modifies some of the saved flags, to prepare the formatting of signed
** integer
**
** params
**	long long int	d		integer to be pushed to buffer
**	t_flags			*flags	pointer of struct with the flags for current
**							conversion
**	t_buffer		*buf	addres of the struct holding all info for the buffer
** return
**	VOID
*/

static void	prepare_format_int10(long long d, unsigned int *nbrlen,
			t_flags *flags)
{
	flags->prcs = (flags->dt && *nbrlen < flags->prcs)
		? flags->prcs - *nbrlen
		: 0;
	*nbrlen += flags->is_signed;
	if (flags->spc && flags->zr && flags->pdn == *nbrlen + 1)
		flags->zr = 0;
	if (flags->spc && !flags->pdn && !flags->prcs && d > 0 && !flags->pls)
		flags->pdn = *nbrlen + 1;
	if (flags->spc && !flags->pls && flags->zr &&
		(flags->pdn > *nbrlen + 1 || (flags->pdn < flags->prcs)))
	{
		flags->zr = 0;
		if (!flags->prcs && flags->pdn > *nbrlen + 1)
			flags->prcs = flags->pdn - *nbrlen - 1;
		else if (flags->pdn < flags->prcs)
			flags->pdn = flags->prcs + *nbrlen + 1;
	}
}

/*
** -------------------------------------------------------------------------- **
** entry point for formatting unsigned integer
**
** params
**	long long unsigned int	d		integer to be pushed to buffer
**	t_flags					*flags	struct with the flags for current
**									conversion
**	t_buffer				*buf	addres of the struct holding all info for
**									the buffer
** return
**	VOID
*/

void		format_int_unsgnd(long long unsigned d, t_flags *flags,
				t_buffer *buf)
{
	unsigned int	nbrlen;

	if (flags->zr && flags->dt && !flags->spc && flags->prcs)
		flags->zr = 0;
	nbrlen = ft_absolute_nbrlen(d, flags->base);
	if (flags->base == 16 && nbrlen == 9 && !flags->ll && !flags->l
			&& !flags->j)
		d = 0;
	if (d == 0 && ((flags->dt && flags->prcs == 0) ||
			(flags->base == 8 && flags->hsh)))
		nbrlen = 0;
	if ((flags->base == 16 && d == 0 && flags->conv != 'p')
			|| (flags->base == 8 && flags->prcs > nbrlen))
		flags->hsh = 0;
	flags->prcs = (nbrlen < flags->prcs) ? flags->prcs - nbrlen : 0;
	if (flags->base == 10 && (nbrlen >= flags->pdn || flags->zr || flags->mns))
		print_number_sign(1, flags, buf);
	format_prepend(1, nbrlen, flags, buf);
	if (nbrlen > 0)
		unsigned_itobuf(d, flags->base, buf, flags->is_cap);
	format_append(nbrlen, flags, buf);
}

/*
** -------------------------------------------------------------------------- **
** entry point for formatting signed integer
**
** params
**	long long int	d		int to be pushed to buffer
**	t_flags			*flags	pointer of struct with the flags for current
**							conversion
**	t_buffer		*buf	addres of the struct holding all info for the buffer
** return
**	VOID
*/

void		format_int(long long d, t_flags *flags, t_buffer *buf)
{
	unsigned int	nbrlen;

	if (flags->zr && flags->dt && !flags->spc && flags->prcs)
		flags->zr = 0;
	flags->is_signed = (d < 0 || flags->pls);
	nbrlen = ft_absolute_nbrlen(d, flags->base);
	if (d == 0 && flags->dt && flags->prcs == 1 && !flags->pdn)
		buff_push(buf, "0", 1);
	else
	{
		if (flags->base == 10)
			prepare_format_int10(d, &nbrlen, flags);
		if (flags->dt && d == 0 && flags->prcs == 0)
			nbrlen = 0;
		if (flags->base == 10 &&
				(nbrlen >= flags->pdn || flags->zr || flags->mns))
			print_number_sign((d >= 0), flags, buf);
		format_prepend(d > 0, nbrlen, flags, buf);
		if (!(flags->dt && d == 0 && flags->prcs == 0))
			absolute_itobuf(d, flags->base, buf, flags->is_cap);
		format_append(nbrlen, flags, buf);
	}
}
