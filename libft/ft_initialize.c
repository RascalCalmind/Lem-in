/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_initialize.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 20:16:38 by mvan-hou       #+#    #+#                */
/*   Updated: 2019/09/25 17:23:34 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_freestring(char *str)
{
	free(str);
	str = NULL;
}

void	ft_free(t_list *list, t_buf *buf)
{
	if (buf != NULL)
		free(buf);
	if (list != NULL)
		free(list);
	list = NULL;
	buf = NULL;
}

void	ft_set_list(t_list *list)
{
	list->flags = 0;
	list->minfw = 0;
	list->precision = 0;
	list->argtype = 0;
	list->sign = 1;
	list->capital = 0;
}

void	ft_set_buffer(t_buf *buf)
{
	buf->length = 0;
	buf->count = 0;
	buf->fd = 1;
	buf->string = NULL;
}

void	ft_intialize_structs(t_list *list, t_buf *buf)
{
	ft_set_list(list);
	ft_set_buffer(buf);
}
