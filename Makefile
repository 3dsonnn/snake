# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <efinda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 19:25:46 by efinda            #+#    #+#              #
#    Updated: 2025/05/29 19:41:09 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = snake

SRC =	src/main.c							\
		src/init_snake.c					\
		src/game_over.c						\
		src/setup/mlx.c						\
		src/setup/setup_game.c				\
		src/destroy.c						\
		src/hooks.c							\
		src/movement.c						\
		src/paint.c							\
		src/utils.c							\
		src/did_snake_eat.c					\
		src/sprites.c						\
		src/body_utils.c					\
		src/t_tile/init.c					\
		src/t_tile/free.c					\
		src/t_tile/link.c					\
		src/t_tile/set.c					\
		src/t_tile/utils.c					\
		src/user_interface/checks.c			\
		src/user_interface/prompt_user.c	\

CC = cc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror -I./$(MLXPATH) -O3
READLINE = -lreadline

MY_MLXPATH = my_mlx
MY_MLX = $(MY_MLXPATH)/my_mlx.a

LIBFTPATH = my_mlx/Super-Libft
LIBFT =	$(LIBFTPATH)/libft.a

MLXPATH = my_mlx/minilibx-linux
MLX = $(MLXPATH)/libmlx.a
LIBS =	-L./$(MLXPATH) -lmlx -lX11 -lXext -lm

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(MY_MLX) $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(MY_MLX) $(LIBFT) $(LIBS) $(READLINE) -o $@

$(MY_MLX):
	@$(MAKE) -C $(MY_MLXPATH)

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(MY_MLXPATH) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(MY_MLXPATH) fclean

re: fclean all
	$(MAKE) -s -C $(MY_MLXPATH) re

.PHONY: all clean fclean re
