# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lhageman <lhageman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/13 17:45:16 by lhageman       #+#    #+#                 #
#    Updated: 2020/01/15 17:39:47 by lhageman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

LEM = lem-in
LIBFT = libft/libft.a

CCC = gcc -gc -Wall -Wextra
CCO = gcc -g -Wall -Wextra -o

SRC = ft_lem_in.c
OBJ = $(SRC:%.c=%.o)
TRASH = $(SRC:%.c=%c.~)

all:	$(LEM)

$(LIBFT):
	@$(MAKE) -C libft

%.o: %.c
	@$(CCO) $@ $< -I./libft -c

$(LEM): $(LIBFT) $(OBJ) 
	@echo "\033[0;35mmaking Lem-in\033[0m"
	@$(CCO) $(LEM) $(OBJ) -L ./libft -lft

clean:
	@$(MAKE) clean -C libft
	@rm -f $(OBJ)
	@echo "\033[0;31mCleaning object files \033[0m"
	@rm -f $(TRASH)
	@echo "\033[1;33mCleaning the trash\033[0m"

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -f $(LEM)
	@echo "\033[0;32mClearing executables\033[0m"

re: fclean all