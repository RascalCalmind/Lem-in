/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/05 18:31:54 by mmarcell      #+#    #+#                 */
/*   Updated: 2019/07/25 15:51:15 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** -------------------------------------------------------------------------- **
** saves the format flags '#'-, '0'-, '-'-, '+'-, space-flag and the precision
** in struct flags
**
** params
**	char	*pos	the current postion in the string
**	t_flags	*flags	pointer of struct with the flags for current conversion
** return
**	char	*		the position of the last byte of the last saved flag
*/

static char	*save_formatflag(char *pos, t_flags *flags)
{
	if (*pos == '#')
		flags->hsh = 1;
	else if (*pos == '0')
		flags->zr = 1;
	else if (*pos == '-')
		flags->mns = 1;
	else if (*pos == '+')
		flags->pls = 1;
	else if (*pos == '.')
	{
		flags->dt = 1;
		if ('0' <= *(pos + 1) && *(pos + 1) <= '9')
		{
			flags->prcs = ft_atoi(pos + 1);
			pos = pos + ft_absolute_nbrlen(flags->prcs, 10);
		}
	}
	else if (*pos == ' ')
		flags->spc = 1;
	return (pos);
}

/*
** -------------------------------------------------------------------------- **
** saves the type flags 'h'-, 'hh'-, 'l'-, 'll'-, 'L'-, 'j'-, and 'z'-flag
**
** params
**	char	*pos	the current postion in the string
**	t_flags	*flags	pointer of struct with the flags for current conversion
** return
**	char	*		the position of the last byte of the last saved flag
*/

static char	*save_typeflag(char *pos, t_flags *flags)
{
	if (*pos == 'h' && *(pos + 1) != 'h')
		flags->h = 1;
	else if (*pos == 'h' && *(pos + 1) == 'h')
	{
		flags->hh = 1;
		++pos;
	}
	else if (*pos == 'l' && *(pos + 1) != 'l')
		flags->l = 1;
	else if (*pos == 'l' && *(pos + 1) == 'l')
	{
		flags->ll = 1;
		++pos;
	}
	else if (*pos == 'L')
		flags->lll = 1;
	else if (*pos == 'j')
		flags->j = 1;
	else if (*pos == 'z')
		flags->z = 1;
	return (pos);
}

/*
** -------------------------------------------------------------------------- **
** BONUS: the next va_arg argument is saved into the flag, the wildcard '*'
** stands for
**
** params
**	va_list	ap		list item for the next argument
**	char	*pos	the current postion in the string
**	t_flags	*flags	pointer of struct with the flags for current conversion
** return
**	char	*		the position of the last byte of the last saved flag
*/

char		*save_wildcard(va_list ap, char *pos, t_flags *flags)
{
	int	wildcard;

	wildcard = va_arg(ap, int);
	if (*pos == '.')
	{
		if (wildcard >= 0)
		{
			flags->dt = 1;
			flags->prcs = wildcard;
		}
		return (pos + 1);
	}
	if (wildcard < 0)
	{
		flags->mns = 1;
		wildcard = -1 * wildcard;
	}
	flags->pdn = wildcard;
	return (pos);
}

/*
** -------------------------------------------------------------------------- **
** loops through the given string and saves accuring until the characters dont
** match any flag anymore
**
** params
**	va_list	ap		list item for the next argument
**	char	*pos	the current postion in the string
**	t_flags	*flags	pointer of struct with the flags for current conversion
** return
**	char	*		the pointer to the first character after the flags
*/

char		*save_flags(va_list ap, char *pos, t_flags *flags)
{
	while (('0' <= *pos && *pos <= '9') || *pos == 'h' || *pos == 'l' ||
		*pos == 'L' || *pos == '#' || *pos == '-' || *pos == '+' ||
		*pos == ' ' || *pos == '0' || *pos == '.' || *pos == 'j' ||
		*pos == 'z' || *pos == '*')
	{
		if (*pos == 'L' || *pos == 'h' || *pos == 'l' || *pos == 'j' ||
			*pos == 'z')
			pos = save_typeflag(pos, flags);
		else if ('0' < *pos && *pos <= '9')
		{
			flags->pdn = ft_atoi(pos);
			pos = pos + ft_absolute_nbrlen(flags->pdn, 10) - 1;
		}
		else if (*pos == '#' || *pos == '-' || *pos == '+' || *pos == '0' ||
			(*pos == '.' && *(pos + 1) != '*') || *pos == ' ')
			pos = save_formatflag(pos, flags);
		else if (*pos == '*' || (*pos == '.' && *(pos + 1) == '*'))
			pos = save_wildcard(ap, pos, flags);
		++pos;
	}
	return (pos);
}
