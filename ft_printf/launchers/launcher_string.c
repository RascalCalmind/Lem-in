/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   launcher_string.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 17:16:24 by mmarcell      #+#    #+#                 */
/*   Updated: 2019/07/15 14:10:54 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** -------------------------------------------------------------------------- **
** handles the formatting of character and character-string conversions
**
** params
**	char		*s		address character/character-string
**	t_buffer	*buf	address of the struct holding all info for the buffer
**	t_flags		*flags	address of struct with the flags for current conversion
**	char		is_char	is 1 in case s refers to a single character, 0 in case
**						s refers to string
** return
**	VOID
*/

void		handler_sc(char *s, t_buffer *buf, t_flags *flags, char is_char)
{
	unsigned int len;

	if (s)
		len = is_char ? 1 : ft_strlen(s);
	else
		len = 6;
	if (!flags->dt || flags->prcs > len || (is_char && !flags->prcs))
		flags->prcs = len;
	if (!flags->mns && flags->pdn > flags->prcs)
	{
		if (flags->zr)
			buff_filler(buf, '0', flags->pdn - flags->prcs);
		else
			buff_filler(buf, ' ', flags->pdn - flags->prcs);
	}
	if (s)
		buff_push(buf, s, flags->prcs);
	else
		buff_push(buf, "(null)", flags->prcs);
	if (flags->mns && flags->pdn > flags->prcs)
		buff_filler(buf, ' ', (flags->pdn - flags->prcs));
}

/*
** -------------------------------------------------------------------------- **
** launches character conversion
**
** params
**	va_list			ap	 	list item for the next argument
**	t_buffer		*buf	addres of the struct holding all info for the buffer
**	t_flags			*flags	address of struct with the flags for current
**							conversion
** return
**	VOID
*/

void		launch_c(va_list ap, t_buffer *buf, t_flags *flags)
{
	unsigned int c;

	c = va_arg(ap, unsigned int);
	handler_sc((char *)&c, buf, flags, 1);
}

/*
** -------------------------------------------------------------------------- **
** launches the string conversion
**
** params
**	va_list			ap	 	list item for the next argument
**	t_buffer		*buf	addres of the struct holding all info for the buffer
**	t_flags			*flags	address of struct with the flags for current
**							conversion
** return
**	VOID
*/

void		launch_s(va_list ap, t_buffer *buf, t_flags *flags)
{
	handler_sc(va_arg(ap, char *), buf, flags, 0);
}

/*
** -------------------------------------------------------------------------- **
** intermediate function to handle single character when no known conversion
** character is given
**
** params
**	char		c		character to be printed
**	t_buffer	*buf	addres of the struct holding all info for the buffer
**	t_flags		*flags	address of struct with the flags for current conversion
** return
**	VOID
*/

void		handle_char(char c, t_buffer *buf, t_flags *flags)
{
	handler_sc((char *)&c, buf, flags, 1);
}
