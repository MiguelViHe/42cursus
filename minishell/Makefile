NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

RM = rm -rf

SRCS =	src/minishell.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a


$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) -lreadline
	
$(LIBFT):
	$(MAKE) bonus -C $(LIBFT_DIR)
	
all: $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
