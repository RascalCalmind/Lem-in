# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: wmisiedj <wmisiedj@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/11 16:25:03 by wmisiedj       #+#    #+#                 #
#    Updated: 2019/08/28 15:23:02 by mmarcell      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a

FILES = 	libft/ft_atoi.c \
	libft/ft_bzero.c \
	libft/ft_absolute_nbrlen.c \
	libft/ft_power.c \
	libft/ft_double_power.c \
	libft/ft_absolute_doublelen.c \
	libft/ft_putnstr_fd.c \
	libft/ft_strchr.c \
	libft/ft_strlen.c \
	libft/ft_memset.c \
	launchers/launcher_double.c \
	launchers/launcher_int.c \
	launchers/launcher_n.c \
	launchers/launcher_string.c \
	tools/buffer.c \
	tools/flags.c \
	double/ftobuf.c \
	ft_printf.c \
	integer/formatting_prep.c \
	integer/formatting.c \
	integer/itobuf.c \

OBJECTS = $(FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -rc $(NAME) $(OBJECTS)

%.o: %.c ft_printf.h
	@$(CC) -o $@ -c $< $(FLAGS)

re: fclean $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)
