/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 14:23:50 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/05/21 10:38:40 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <float.h>

# define BUFF_SIZE 512
# define CONV_CHAR_START 'B'
# define CONV_CHAR_END 121

typedef struct		s_flags
{
	unsigned int	hh			: 1;
	unsigned int	h			: 1;
	unsigned int	ll			: 1;
	unsigned int	l			: 1;
	unsigned int	lll			: 1;
	unsigned int	hsh			: 1;
	unsigned int	zr			: 1;
	unsigned int	mns			: 1;
	unsigned int	pls			: 1;
	unsigned int	spc			: 1;
	unsigned int	dt			: 1;
	unsigned int	j			: 1;
	unsigned int	z			: 1;
	unsigned int	is_cap		: 1;
	unsigned int	is_signed	: 1;
	unsigned int	pdn;
	unsigned int	prcs;
	unsigned char	conv;
	unsigned int	base;
}					t_flags;

typedef struct		s_buffer
{
	char			str[BUFF_SIZE + 1];
	ssize_t			count;
	ssize_t			idx;
	int				fd;
}					t_buffer;

typedef void		(*t_conversion_table[CONV_CHAR_END - CONV_CHAR_START])
					(va_list ap, t_buffer *buf, t_flags *flags);

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);

void				buff_push(t_buffer *buf, char *str, size_t n);
void				buff_print_dump(t_buffer *buf);
void				buff_filler(t_buffer *buf, char c, unsigned int n);
char				*save_flags(va_list ap, char *pos, t_flags *flags);
void				absolute_itobuf(long long nb, unsigned int base,
					t_buffer *buf, int is_cap);
void				unsigned_itobuf(long long unsigned nb, unsigned int base,
					t_buffer *buf, int is_cap);
void				itobuf(long long int nb, unsigned int base, t_buffer *buf,
					int is_cap);
void				ftobuf(long double num, unsigned int precision,
					t_buffer *buf);
void				longftobuf(long double ldb, unsigned int prcs,
					unsigned int len, t_buffer *buf);
long double			rounder(int precision);

void				handle_char(char c, t_buffer *buf, t_flags *flags);
void				handler_sc(char *s, t_buffer *buf, t_flags *flags,
					char is_char);

void				launch_int10(va_list ap, t_buffer *buf, t_flags *flags);
void				launch_int10_unsgnd(va_list ap, t_buffer *buf,
					t_flags *flags);
void				launch_int8	(va_list ap, t_buffer *buf, t_flags *flags);
void				launch_int16(va_list ap, t_buffer *buf, t_flags *flags);
void				launch_int2(va_list ap, t_buffer *buf, t_flags *flags);
void				launch_double(va_list ap, t_buffer *buf, t_flags *flags);
void				launch_s(va_list ap, t_buffer *buf, t_flags *flags);
void				launch_c(va_list ap, t_buffer *buf, t_flags *flags);
void				launch_n(va_list ap, t_buffer *buf, t_flags *flags);

void				format_int(long long d, t_flags *flags, t_buffer *buf);
void				format_int_unsgnd(unsigned long long d, t_flags *flags,
					t_buffer *buf);
void				print_number_sign(int is_positive, t_flags *flags,
					t_buffer *buf);
void				format_prepend(int is_positive, unsigned int nbrlen,
					t_flags *flags, t_buffer *buf);
void				format_append(unsigned int nbrlen, t_flags *flags,
					t_buffer *buf);

void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *str);
unsigned int		ft_absolute_nbrlen(long long int nbr, int base);
long long			ft_power(int base, unsigned int exp);
ssize_t				ft_putnstr_fd(const char *str, size_t len, int fd);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *str);
void				*ft_memset(void *b, int c, size_t len);
long double			ft_ldouble_power(long double base, int exp);
double				ft_double_power(double base, int exp);
unsigned int		ft_absolute_doublelen(long double ld, unsigned int prcs);

#endif
