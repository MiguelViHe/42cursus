# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 10:57:49 by mvidal-h          #+#    #+#              #
#    Updated: 2024/06/13 12:54:36 by mvidal-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address

RM = rm -f

SRCS =	push_swap.c \
		swap.c \
		push.c \
		rotate.c \
		reverse_rotate.c \
		free.c \
		errors.c \
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
		
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

all: $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re