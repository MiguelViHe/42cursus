# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 17:22:41 by mvidal-h          #+#    #+#              #
#    Updated: 2024/08/10 10:13:28 by mvidal-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
MLX42_FLAGS = -ldl -lglfw -pthread -lm

HEADERS	= -I $(MLX42_DIR)/include

RM = rm -rf

SRCS =	base/so_long.c \
		base/map_errors.c \
		base/check_map.c \
		base/check_map_elems.c \
		base/files.c \
		base/generate_map.c \
		base/copy_map.c \
		base/check_path.c \
		base/printing.c \
		base/game.c \
		base/game_images.c \
		base/freeing.c \
		base/hooks.c \
		base/movements.c \
		base/win.c \


SRCS_BONUS =	so_long_bonus.c \
				map_errors_bonus.c \
				check_map_bonus.c \
				check_map_elems_bonus.c \
				files_bonus.c \
				generate_map_bonus.c \
				copy_map_bonus.c \
				check_path_bonus.c \
				printing_bonus.c \
				game_bonus.c \
				freeing_bonus.c \
				load_images_bonus.c \
				put_images_bonus.c \
				put_images_elem_bonus.c \
				instances_image_bonus.c \
				hooks_bonus.c \
				movements_bonus.c \
				actions_in_game_bonus.c \
				win_loose_bonus.c \
				score_bonus.c \
				enemies_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX42_DIR = mlx42
MLX42 = $(MLX42_DIR)/build/libmlx42.a

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX42) $(MLX42_FLAGS) $(HEADERS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX42) $(MLX42_FLAGS) $(HEADERS) -o $(NAME_BONUS)

$(LIBFT):
	$(MAKE) bonus -C $(LIBFT_DIR)
	
all: libmlx42 $(NAME) $(NAME_BONUS)

bonus: $(NAME_BONUS)

libmlx42:
	cmake $(MLX42_DIR) -B $(MLX42_DIR)/build && make -C $(MLX42_DIR)/build -j4

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(MLX42_DIR)/build
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus libmlx42
