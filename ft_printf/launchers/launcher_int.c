/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   launcher_int.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/11 18:11:07 by mmarcell      #+#    #+#                 */
/*   Updated: 2019/07/16 17:10:37 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** -------------------------------------------------------------------------- **
** launches the integer conversion base 10
**
** params
**	va_list		ap		list item for the next argument
**	t_buffer	*buf	address of the struct holding all info for the buffer
**	t_flags		*flags	address of struct with the flags for current
**							conversion
** return
**	VOID
*/

void			launch_int10(va_list ap, t_buffer *buf, t_flags *flags)
{
	flags->base = 10;
	if (flags->j || flags->z)
		format_int(va_arg(ap, ssize_t), flags, buf);
	else if (flags->ll || flags->conv == 'D' || flags->conv == 'I')
		format_int(va_arg(ap, long long int), flags, buf);
	else if (flags->l)
		format_int(va_arg(ap, long int), flags, buf);
	else if (flags->h)
		format_int((short)va_arg(ap, int), flags, buf);
	else if (flags->hh)
		format_int((char)va_arg(ap, int), flags, buf);
	else
		format_int(va_arg(ap, int), flags, buf);
}

/*
** -------------------------------------------------------------------------- **
** launches the unsigned integer conversion base 10
**
** params
**	va_list		ap		list item for the next argument
**	t_buffer	*buf	address of the struct holding all info for the buffer
**	t_flags		*flags	address of struct with the flags for current
**							conversion
** return
**	VOID
*/

void			launch_int10_unsgnd(va_list ap, t_buffer *buf, t_flags *flags)
{
	flags->base = 10;
	if (flags->j)
		format_int_unsgnd(va_arg(ap, size_t), flags, buf);
	else if (flags->ll || flags->z)
		format_int_unsgnd(va_arg(ap, unsigned long long int), flags, buf);
	else if (flags->l || flags->conv == 'U')
		format_int_unsgnd(va_arg(ap, unsigned long int), flags, buf);
	else if (flags->h)
		format_int_unsgnd((unsigned short)va_arg(ap, unsigned int), flags,
			buf);
	else if (flags->hh)
		format_int_unsgnd((unsigned char)va_arg(ap, unsigned int), flags,
			buf);
	else
		format_int_unsgnd(va_arg(ap, unsigned int), flags, buf);
}

/*
** -------------------------------------------------------------------------- **
** launches the integer conversion base 8
**
** params
**	va_list			ap		list item for the next argument
**	t_buffer		*buf	address of the struct holding info for the buffer
**	t_flags			*flags	address of struct with the flags for current
**							conversion
** return
**	VOID
*/

void			launch_int8(va_list ap, t_buffer *buf, t_flags *flags)
{
	flags->base = 8;
	if (flags->j)
		format_int_unsgnd(va_arg(ap, size_t), flags, buf);
	else if (flags->ll || flags->z || flags->conv == 'O')
		format_int_unsgnd(va_arg(ap, unsigned long long int), flags, buf);
	else if (flags->l)
		format_int_unsgnd(va_arg(ap, unsigned long int), flags, buf);
	else if (flags->h)
		format_int_unsgnd((unsigned short)va_arg(ap, unsigned int), flags,
			buf);
	else if (flags->hh)
		format_int_unsgnd((unsigned char)va_arg(ap, unsigned int), flags,
			buf);
	else
		format_int_unsgnd(va_arg(ap, unsigned int), flags, buf);
}

/*
** -------------------------------------------------------------------------- **
** launches the integer conversion base 16
**
** params
**	va_list			ap		list item for the next argument
**	t_buffer		*buf	address of the struct holding info for the buffer
**	t_flags			*flags	address of struct with the flags for current
**							conversion
** return
**	VOID
*/

void			launch_int16(va_list ap, t_buffer *buf, t_flags *flags)
{
	flags->base = 16;
	if (flags->conv == 'p' || flags->conv == 'P')
	{
		flags->ll = 1;
		flags->hsh = 1;
	}
	flags->is_cap = (flags->conv == 'X');
	if (flags->j)
		format_int_unsgnd(va_arg(ap, size_t), flags, buf);
	else if (flags->ll || flags->z)
		format_int_unsgnd(va_arg(ap, unsigned long long int), flags, buf);
	else if (flags->l)
		format_int_unsgnd(va_arg(ap, unsigned long int), flags, buf);
	else if (flags->h)
		format_int_unsgnd((unsigned short)va_arg(ap, unsigned int), flags,
			buf);
	else if (flags->hh)
		format_int_unsgnd((unsigned char)va_arg(ap, unsigned int), flags,
			buf);
	else
		format_int_unsgnd(va_arg(ap, unsigned int), flags, buf);
}

/*
** -------------------------------------------------------------------------- **
** launches the integer conversion base 2 (BONUS)
**
** params
**	va_list			ap		list item for the next argument
**	t_buffer		*buf	address of the struct holding info for the buffer
**	t_flags			*flags	address of struct with the flags for current
**							conversion
** return
**	VOID
*/

void			launch_int2(va_list ap, t_buffer *buf, t_flags *flags)
{
	flags->base = 2;
	if (flags->j)
		format_int_unsgnd(va_arg(ap, size_t), flags, buf);
	else if (flags->ll || flags->z)
		format_int_unsgnd(va_arg(ap, unsigned long long int), flags, buf);
	else if (flags->l || flags->conv == 'B')
		format_int_unsgnd(va_arg(ap, unsigned long int), flags, buf);
	else if (flags->h)
		format_int_unsgnd((unsigned short)va_arg(ap, unsigned int), flags,
			buf);
	else if (flags->hh)
		format_int_unsgnd((unsigned char)va_arg(ap, unsigned int), flags,
			buf);
	else
		format_int_unsgnd(va_arg(ap, unsigned int), flags, buf);
}
