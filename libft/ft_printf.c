/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 16:43:45 by lhageman       #+#    #+#                */
/*   Updated: 2019/09/25 17:36:43 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_findformat(t_list *list, t_buf *buf)
{
	char				*str;
	char				c;
	unsigned long long	ptr;

	if (list->argtype == 's')
	{
		str = va_arg(list->varg, char *);
		if (str == NULL)
			ft_string(list, buf, "(null)");
		else
			ft_string(list, buf, str);
	}
	else if (list->argtype == 'c')
	{
		c = (char)va_arg(list->varg, int);
		ft_char(list, buf, c);
	}
	else if (list->argtype == 'p')
	{
		ptr = (unsigned long long)va_arg(list->varg, unsigned long long);
		ft_create_p(ptr, list, buf);
	}
	else
		ft_nextformat(list, buf);
}

int		ft_printf2(const char *format, t_list *list, t_buf *buf)
{
	int i;
	int ret;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_set_list(list);
			ret = ft_formatcheck(format, i + 1, list);
			if (ret >= 0)
			{
				ft_findformat(list, buf);
				i += ret;
			}
			else
				return (buf->count);
		}
		else
			ft_put_to_buf(buf, format[i]);
		i++;
	}
	return (buf->count);
}

int		ft_printf(const char *format, ...)
{
	t_list	*list;
	t_buf	*buf;
	int		ret;

	buf = (t_buf*)malloc(sizeof(t_buf));
	if (!buf)
		return (0);
	list = (t_list*)malloc(sizeof(t_list));
	if (!list)
	{
		ft_free(list, buf);
		return (0);
	}
	va_start(list->varg, format);
	ft_set_buffer(buf);
	ret = ft_printf2(format, list, buf);
	ft_printbuf(buf);
	ret = buf->count;
	ft_free(list, buf);
	va_end(list->varg);
	return (ret);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	t_list	*list;
	t_buf	*buf;
	int		ret;

	buf = (t_buf*)malloc(sizeof(t_buf));
	if (!buf)
		return (0);
	list = (t_list*)malloc(sizeof(t_list));
	if (!list)
	{
		ft_free(list, buf);
		return (0);
	}
	va_start(list->varg, format);
	ft_set_buffer(buf);
	if (fd)
		buf->fd = fd;
	ret = ft_printf2(format, list, buf);
	ft_printbuf(buf);
	ret = buf->count;
	ft_free(list, buf);
	va_end(list->varg);
	return (ret);
}

int		ft_sprintf(char *str, const char *format, ...)
{
	t_list	*list;
	t_buf	*buf;
	int		ret;

	if (!str)
		return (0);
	buf = (t_buf*)malloc(sizeof(t_buf));
	if (!buf)
		return (0);
	list = (t_list*)malloc(sizeof(t_list));
	if (!list)
	{
		ft_free(list, buf);
		return (0);
	}
	va_start(list->varg, format);
	ft_set_buffer(buf);
	buf->string = str;
	ft_printf2(format, list, buf);
	ft_printbuf(buf);
	str[buf->count] = '\0';
	ret = buf->count;
	ft_free(list, buf);
	va_end(list->varg);
	return (ret);
}
