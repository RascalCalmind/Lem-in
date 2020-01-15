/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_buf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 14:27:33 by lhageman       #+#    #+#                */
/*   Updated: 2019/09/25 17:20:15 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_buf_to_string(t_buf *buf)
{
	int i;

	i = 0;
	while (i < buf->length)
	{
		buf->string[i + buf->count] = buf->buf[i];
		i++;
	}
}

void	ft_printbuf(t_buf *buf)
{
	if (buf->string == NULL)
		write(buf->fd, &buf->buf, buf->length);
	else
		ft_buf_to_string(buf);
	buf->count += (size_t)buf->length;
	buf->length = 0;
}

void	ft_put_to_buf(t_buf *buf, char c)
{
	buf->buf[buf->length] = c;
	buf->length++;
	if (buf->length == 1024)
		ft_printbuf(buf);
}

void	ft_string_to_buf(t_buf *buf, char *str, size_t len)
{
	while (len > 0)
	{
		ft_put_to_buf(buf, *str);
		str++;
		len--;
	}
}

void	ft_number_to_buf(t_buf *buf, char *str, unsigned long long n,
			int size)
{
	if (n == ((unsigned long long)9223372036854775807 + 1))
		ft_string_to_buf(buf, "-9223372036854775808", 20);
	else
		ft_string_to_buf(buf, str, size);
}
