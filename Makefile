# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lhageman <lhageman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/13 17:45:16 by lhageman       #+#    #+#                 #
#    Updated: 2020/03/11 17:16:53 by lhageman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

LEM = lem-in
LIBFT = libft/libft.a

CCC = gcc -gc -Wall -Wextra -fsanitize=address -fno-omit-frame-pointer
CCO = gcc -g -Wall -Wextra -o

SRC =	ft_lem_in.c \
		ft_free_lem.c \
		./hashtable/ft_hash.c \
		./errors/ft_error.c \
		ft_create.c \
		ft_store.c \
		ft_room_check.c \
		ft_contains.c \
		ft_print_lemin_list.c \
		ft_connection.c \
		ft_file.c \
		ft_ants.c \
		./sorting/ft_bfs.c \
		./sorting/ft_find_room.c \
		./sorting/ft_queue.c \
		./sorting/ft_max_flow.c \
		./sorting/ft_dfs.c
		

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