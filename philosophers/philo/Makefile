NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread -g -fsanitize=address

RM = rm -rf

SRCS =	src/philo.c \
		src/check_args.c \
		src/mutex.c \
		src/initialization.c \
		src/time.c \
		src/checker_referee.c \
		src/check_philos.c \
		src/freeing.c \
		src/actions.c \
		src/functions/ft_atoi.c \
		src/functions/ft_atol.c \
		src/functions/ft_atost.c \
		src/functions/ft_usleep.c \
		src/functions/ft_isdigit.c \
		src/functions/ft_isspace.c \

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		
all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
