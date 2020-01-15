/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 16:43:33 by lhageman       #+#    #+#                */
/*   Updated: 2019/09/25 15:37:08 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# define FLAG_MINUS (1 << 0)
# define FLAG_PLUS (1 << 1)
# define FLAG_SPACE (1 << 2)
# define FLAG_ZERO (1 << 3)
# define FLAG_HASH (1 << 4)
# define FLAG_MINFW (1 << 5)
# define FLAG_PRECISION (1 << 6)
# define FLAG_SHORT (1 << 7)
# define FLAG_HH (1 << 8)
# define FLAG_LONG (1 << 9)
# define FLAG_LL (1 << 10)
# define FLAG_LD (1 << 11)
# define FLAG_H (1 << 12)
# define BIG_F (1 << 13)

# define MINUS_SET (list->flags & FLAG_MINUS) == FLAG_MINUS
# define PLUS_SET (list->flags & FLAG_PLUS) == FLAG_PLUS
# define SPACE_SET (list->flags & FLAG_SPACE) == FLAG_SPACE
# define ZERO_SET (list->flags & FLAG_ZERO) == FLAG_ZERO
# define HASH_SET (list->flags & FLAG_HASH) == FLAG_HASH
# define MINFW_SET (list->flags & FLAG_MINFW) == FLAG_MINFW
# define PRECISION_SET (list->flags & FLAG_PRECISION) == FLAG_PRECISION
# define SHORT_SET (list->flags & FLAG_SHORT) == FLAG_SHORT
# define HH_SET (list->flags & FLAG_HH) == FLAG_HH
# define LONG_SET (list->flags & FLAG_LONG) == FLAG_LONG
# define LL_SET (list->flags & FLAG_LL) == FLAG_LL
# define LD_SET (list->flags & FLAG_LD) == FLAG_LD
# define H_SET (list->flags & FLAG_H) == FLAG_H
# define BIG_F_SET (list->flags & BIG_F) == BIG_F
# define PRECISION_ZERO (PRECISION_SET && list->precision == 0)

typedef struct		s_list
{
	uint16_t	flags;
	int			minfw;
	int			precision;
	char		argtype;
	char		sign;
	char		capital;
	int			color;
	va_list		varg;
}					t_list;

typedef struct		s_buf
{
	char			buf[1024];
	short			length;
	size_t			count;
	int				fd;
	char			*string;
}					t_buf;

typedef struct		s_num
{
	unsigned long long	value;
	int					base;
	int					size;
}					t_num;

typedef struct		s_time
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
}					t_time;

/*
** PRINTF
*/

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_sprintf(char *str, const char *format, ...);

/*
** PARSER FUNCTIONS
*/

int					ft_isformat(char c);
int					ft_isflagchar(char c);
int					ft_formatcheck(const char *format, int i,
					t_list *list);
int					ft_set_flags(const char *format, t_list *list);
int					ft_order(const char *str);
int					ft_flags(const char *format, t_list *list);

void				ft_nextformat(t_list *list, t_buf *buf);
void				ft_create_p(unsigned long long ptr, t_list *list,
					t_buf *buf);
void				ft_create_f(long double flo, t_list *list, t_buf *buf);
void				ft_percent(t_list*list, t_buf *buf);
void				ft_create_u(unsigned long long num, t_list *list,
					t_buf *buf);

/*
** INITIALIZING/CLEANUP FUNCTIONS
*/

void				ft_set_list(t_list *list);

void				ft_free(t_list *list, t_buf *buf);
void				ft_freestring(char *str);

/*
** BUFFER FUNCTIONS
*/

void				ft_set_buffer(t_buf *buf);

void				ft_put_to_buf(t_buf *buf, char c);
void				ft_printbuf(t_buf *buf);
void				ft_string_to_buf(t_buf *buf, char *str, size_t len);
void				ft_number_to_buf(t_buf *buf, char *str,
					unsigned long long n, int size);
void				ft_print_sign(t_list *list, t_buf *buf);
void				ft_print_width(t_list *list, t_buf *buf, int size);

/*
** MATH FUNCTIONS
*/

int					ft_getsize(unsigned long long n, unsigned int base);

long long			ft_abs(long long nbr);
long long			ft_minimum(long long nbr, long long minimum);
long long			ft_power(long long n, int power);

long double			ft_abs_float(long double nbr);

/*
** ARGUMENT SPECIFIC FUNCTIONS
*/

/*
** d, i, o, u, x, X, b
*/

int					ft_binary_size(t_list *list, unsigned long long num);

long long			ft_int_length(t_list *list, long long num);

unsigned long long	ft_oux_length(t_list *list, unsigned long long num);

void				print_binary(uint16_t flag_num);
void				ft_pretoa_base(t_list *list, t_buf *buf,
					unsigned long long nbr, int base);
void				ft_itoa_base(t_list *list, t_buf *buf, t_num n);
void				ft_int_precision(t_list *list, t_buf *buf, int size);
void				ft_btoa(t_list *list, t_buf *buf, unsigned long long num,
					int size);
void				ft_integer(t_list *list, t_buf *buf, long long dble);
void				ft_xotoa_base(t_list *list, t_buf *buf,
					unsigned long long n, int base);

t_num				ft_create_num(t_list *list, unsigned long long n, int base);

/*
** c, s, p
*/

void				ft_char(t_list *list, t_buf *buf, char str);
void				ft_string(t_list *list, t_buf *buf, char *str);

/*
** floats
*/

int					ft_inf_nan(t_list *list, t_buf *buf, long double num);

void				print_float(void *flo);
void				ft_float(t_list *list, t_buf *buf, long double num);
void				ft_massive_floats(t_list *list, t_buf *buf,
					long double num, int prec);
void				ft_ftoa_base(t_list *list, t_buf *buf, long long nbr,
					int base);
void				ft_high_precision(t_list *list, t_buf *buf, long long in,
					long double flo);
void				ft_round(long long *in, long long *dec, int rnd, int prec);
void				ft_print_front(t_list *list, t_buf *buf, long long integer);

/*
** bonus
*/

void				ft_time(int epoch, t_list *list, t_buf *buf);
void				ft_minute_to_string(int minute, char *str);
void				ft_hour_to_string(int hour, char *str);
void				ft_day_to_string(int day, char *str);
void				ft_month_to_string(int month, char *str);
void				ft_year_to_string(int year, char *str);
int					ft_month(int month, int year);
char				*ft_time_string(t_time time);
void				ft_set_list_time(t_time *time);

#endif
