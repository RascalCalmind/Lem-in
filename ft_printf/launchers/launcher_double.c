/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   launcher_double.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 17:04:45 by mmarcell      #+#    #+#                 */
/*   Updated: 2019/07/29 11:15:21 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	print_sign(long double ldb, t_buffer *buf, t_flags *flags)
{
	if (ldb < 0)
		buff_push(buf, "-", 1);
	if (ldb >= 0 && flags->pls)
		buff_push(buf, "+", 1);
}

/*
** -------------------------------------------------------------------------- **
** handles the fromating of the f-conversion
**
** params
**	long double		ldb		number to be printed
**	t_buffer		*buf	addres of the struct holding all info for the buffer
**	t_flags			*flags	pointer of struct with the flags for current
**							conversion
** return
**	VOID
*/

static void	format_double(long double ldb, t_buffer *buf, t_flags *flags)
{
	unsigned int	len;

	flags->prcs = (!flags->dt) ? 6 : flags->prcs;
	flags->dt = 1;
	len = ft_absolute_doublelen(ldb + rounder(flags->prcs), flags->prcs);
	len = (ldb < 0 || flags->spc || flags->pls) ? ++len : len;
	if (flags->spc && ldb >= 0)
		buff_push(buf, " ", 1);
	if (flags->zr || flags->mns)
		print_sign(ldb, buf, flags);
	if (!flags->mns && len < flags->pdn)
		flags->zr ? buff_filler(buf, '0', flags->pdn - len) :
					buff_filler(buf, ' ', flags->pdn - len);
	if (!(flags->zr || flags->mns))
		print_sign(ldb, buf, flags);
	if (ldb <= ULLONG_MAX)
		ftobuf(ldb, flags->prcs, buf);
	else
		longftobuf(ldb, flags->prcs, len, buf);
	if (flags->mns && len < flags->pdn)
		buff_filler(buf, ' ', flags->pdn - len);
}

/*
** -------------------------------------------------------------------------- **
** launches the float conversion
** checks if the argument is a valid number
**
** params
**	va_list			ap		list item for the next argument
**	t_buffer		*buf	addres of the struct holding all info for the buffer
**	t_flags			*flags	pointer of struct with the flags for current
**							conversion
** return
**	VOID
*/

void		launch_double(va_list ap, t_buffer *buf, t_flags *flags)
{
	double			db;
	long double		ldb;

	if (flags->lll)
		ldb = va_arg(ap, long double);
	else
	{
		db = va_arg(ap, double);
		ldb = db;
	}
	if (ldb != ldb)
		handler_sc("nan", buf, flags, 0);
	else if (ldb > LDBL_MAX)
		handler_sc("inf", buf, flags, 0);
	else if (ldb < -LDBL_MAX)
		handler_sc("-inf", buf, flags, 0);
	else
		format_double(ldb, buf, flags);
}
