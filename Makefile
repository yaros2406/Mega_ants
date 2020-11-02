# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkuhic <lkuhic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/19 11:32:25 by bshaquan          #+#    #+#              #
#    Updated: 2020/02/19 19:42:49 by lkuhic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = lem-in
CFLAGS = -Wall -Wextra -Werror -g3
#CFLAGS = -Wall -Wextra -Werror -O3 -ffreestanding -fno-builtin -flto
#CFLAGS = -Wall -Wextra -g3 -fsanitize=address,undefined -Wpadded
LIBH = libft/inc
INC = inc/
HEAD = $(INC)lem_in.h
LIBA = libft/libft.a
SRC_DIR = src/

SRC_FILES = ants_print.c ants_track.c bfs_init.c bfs_paths.c \
			bfs_rebuild.c bfs_reset.c graph_create.c graph_elem.c \
			graph_free.c graph_out.c graph_print.c lem_in.c \
			parsing.c parsing_duplicates.c parsing_free.c \
			parsing_validate.c paths.c paths_tools.c solver.c \
			solver_tools.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES)) visual/visualizer.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBA) $(OBJ) 
	$(CC) $(CFLAGS) -I$(LIBH) -I$(INC) -Llibft -lft -o $@ $(OBJ)
	printf "$(GREEN)created: $@\n$(NC)"

$(LIBA): FORCE
	$(MAKE) -C libft

FORCE:

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -I$(LIBH) -I$(INC) -o $@ -c $<
	printf "$(CYAN)compiling: $<\n$(NC)"

clean:
	$(MAKE) -C libft fclean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	printf "$(RED)deleted: $(NAME)\n$(NC)"

re: fclean all

CYAN=\033[0;36m
GREEN=\033[0;32m
RED=\033[0;31m
NC=\033[0m

.PHONY: all clean fclean re
.SILENT:
