# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lhageman <lhageman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/07/24 22:50:24 by lhageman       #+#    #+#                 #
#    Updated: 2020/01/16 14:54:22 by wmisiedj      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCC =	ft_itoa.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_isdigit.c \
	ft_isspace.c \
	ft_atoi.c \
	ft_bzero.c \
	ft_memset.c \
	ft_strsub.c \
	ft_strnew.c \
	ft_strnjoin.c \
	ft_math.c \
	ft_buf.c \
	ft_flags.c \
	ft_float.c \
	ft_initialize.c \
	ft_integer.c \
	ft_itoa_base.c \
	ft_order.c \
	ft_perc.c \
	ft_printf.c \
	ft_string.c \
	ft_width.c \
	ft_xotoa_base.c \
	ft_numbers.c \
	ft_massive_floats.c \
	ft_inf_nan.c \
	ft_dioux.c \
	ft_cspf.c \
	ft_format.c \
	ft_binary.c \
	ft_time.c \
	ft_time2.c \
	ft_time3.c \
	ft_strcmp.c \
	ft_strclr.c \
	get_next_line.c \
	ft_strsplit.c \
	ft_strsub.c \
	ft_strclen.c \
	ft_glstnew.c \
	ft_memalloc.c \
	ft_memcpy.c \
	ft_strjoin.c \
	ft_strchr.c \
	ft_char_arr_len.c \
	ft_int_arr_len.c \
	ft_strncmp.c

SRCO	= $(SRCC:%.c=%.o)
TRASH	= $(SRCC:%.c=%.c~)

SRCH	= libft.h ft_printf.h
CC	= gcc -c -Wall -Wextra -Werror

all: $(NAME)
$(NAME):
	@$(CC) -I $(SRCH) $(SRCC)
	@ar rc $(NAME) $(SRCO)
	@ranlib $(NAME)
clean:
	@rm -f $(SRCO) $(TRASH)
fclean: clean
	@rm -f $(NAME)
re: fclean all
