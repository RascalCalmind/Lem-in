# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lhageman <lhageman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/13 17:45:16 by lhageman      #+#    #+#                  #
#    Updated: 2020/05/21 11:00:39 by lhageman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

LEM = lem-in

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
LIBFLAGS = -lft -L./libft/ -lftprintf -L./ft_printf/

CCC = gcc -gc -Wall -Wextra -Werror
CCO = gcc -g -Wall -Wextra -Werror -o

SRC =	ft_lem_in.c \
		ft_free_lem.c \
		ft_free_paths.c \
		./hashtable/ft_hash.c \
		./errors/ft_error.c \
		ft_create.c \
		ft_store.c \
		ft_contains.c \
		ft_print_lemin_list.c \
		ft_connection.c \
		ft_file.c \
		ft_ants.c \
		./sorting/ft_bfs.c \
		./sorting/ft_find_room.c \
		./sorting/ft_queue.c \
		./sorting/ft_max_flow.c \
		./sorting/ft_dfs.c \
		ft_lists.c
		

OBJ = $(SRC:%.c=%.o)
TRASH = $(SRC:%.c=%c.~)

all:	$(LEM)

$(LIBFT):
	@$(MAKE) -C libft

$(PRINTF):
	@$(MAKE) -C ft_printf

%.o: %.c
	@$(CCO) $@ $< -I./libft -I./ft_printf -c

$(LEM): $(LIBFT) ${PRINTF} $(OBJ)
	@echo "\033[0;35mmaking Lem-in\033[0m"
	@$(CCO) $(LEM) $(OBJ) ${LIBFLAGS}

clean:
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C ft_printf
	@rm -f $(OBJ)
	@echo "\033[0;31mCleaning object files \033[0m"
	@rm -f $(TRASH)
	@echo "\033[1;33mCleaning the trash\033[0m"

fclean: clean
	@$(MAKE) fclean -C libft
	@$(MAKE) fclean -C ft_printf
	@rm -f $(LEM)
	@echo "\033[0;32mClearing executables\033[0m"

re: fclean all