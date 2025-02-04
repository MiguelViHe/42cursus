NAME = pipex
BONUS = pipex_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

RM = rm -rf

SRCS =			pipex.c \
				pipex_utils.c \
				ft_split_squotes.c \
				printing.c \

SRCS_BONUS =	bonus/pipex_bonus.c \
				bonus/pipex_utils_bonus.c \
				bonus/here_doc_bonus.c \
				pipex_utils.c \
				ft_split_squotes.c \
				printing.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a


$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "------------\n| Done! 👌 |\n------------\n"

$(BONUS): $(OBJS_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(BONUS)
	@echo "------------\n| Done! 👌 |\n------------\n"
	
$(LIBFT):
	@$(MAKE) bonus -sC $(LIBFT_DIR)
	
all: $(NAME)

bonus: $(BONUS)

clean:
	@$(MAKE) clean -sC $(LIBFT_DIR)
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@$(MAKE) fclean -sC $(LIBFT_DIR)
	@$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
