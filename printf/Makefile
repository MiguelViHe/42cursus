NAME = libftprintf.a

CC = gcc

AR = ar rcs

CFLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address

SRCS =	ft_printf.c \
		ft_putnbr.c \
		ft_putnbr_base.c \
		ft_putptr.c \
		ft_printf_utils.c \


OBJS = $(SRCS:.c=.o)

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

re: fclean all

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)


.PHONY: all clean fclean re
