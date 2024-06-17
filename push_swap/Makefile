# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 10:57:49 by mvidal-h          #+#    #+#              #
#    Updated: 2024/06/17 11:48:55 by mvidal-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

CC = gcc

CFLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address

RM = rm -f

SRC_PS = push_swap.c \

SRCS =	swap.c \
		push.c \
		rotate.c \
		reverse_rotate.c \
		free.c \
		errors.c \
		print_error.c \
		index_stack.c \
		position_stack.c \
		sort_basics.c \
		check_sorting.c \
		generate_stack.c \
		sort_stack.c \
		calculate_cost.c \
		lst_utils.c \
		numbers.c \
		sort_long.c \
		move_to_b.c \
		opposite_movs.c \
		same_mov.c \

BONUS_SRC = checker_bonus/checker.c

OBJ_PS = $(SRC_PS:.c=.o)
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_PS) $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ_PS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(BONUS): $(OBJS) $(BONUS_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) $(LIBFT) $(PRINTF) -o $(BONUS)

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

all: $(NAME) $(BONUS)

bonus: $(BONUS)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)
	$(RM) $(OBJ_PS) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus