# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lhageman <lhageman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/07/24 22:50:24 by lhageman      #+#    #+#                  #
#    Updated: 2020/05/15 15:39:43 by lhageman      ########   odam.nl          #
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
	ft_strncmp.c \
	ft_strisint.c \
	ft_sqrt.c

SRCO	= $(SRCC:%.c=%.o)
TRASH	= $(SRCC:%.c=%.c~)

SRCH	= libft.h
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
