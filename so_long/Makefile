# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 17:22:41 by mvidal-h          #+#    #+#              #
#    Updated: 2024/08/01 11:00:06 by mvidal-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
MLX42_FLAGS = -ldl -lglfw -pthread -lm

HEADERS	= -I $(MLX42_DIR)/include

RM = rm -rf

SRCS =	so_long.c \
		map_errors.c \
		check_map.c \
		check_map_elems.c \
		files.c \
		generate_map.c \
		copy_map.c \
		check_path.c \
		printing.c \
		game.c \
		freeing.c \
		game_images.c \
		hooks.c \
		movements.c \
		win.c \
		score.c \

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX42_DIR = mlx42
MLX42 = $(MLX42_DIR)/build/libmlx42.a

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX42) $(MLX42_FLAGS) $(HEADERS) -o $(NAME)

$(LIBFT):
	$(MAKE) bonus -C $(LIBFT_DIR)
	
all: libmlx42 $(NAME)

libmlx42:
	cmake $(MLX42_DIR) -B $(MLX42_DIR)/build && make -C $(MLX42_DIR)/build -j4

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(MLX42_DIR)/build
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus libmlx42
