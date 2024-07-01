NAME = libft.a

CC = gcc

AR = ar rcs

CFLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address

SRCS =	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c\
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_atol.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		get_next_line.c \
		get_next_line_utils.c \

SRCS_PRINTF =	printf/ft_printf.c \
				printf/ft_putnbr.c \
				printf/ft_putnbr_base.c \
				printf/ft_putptr.c \
				printf/ft_printf_utils.c \

SRCS_BONUS =	ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c \
				ft_lstprev_bonus.c \

OBJS = $(SRCS:.c=.o)

OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(OBJS_BONUS) $(OBJS) $(OBJS_PRINTF)
	$(AR) $(NAME) $(OBJS) $(OBJS_PRINTF) $(OBJS_BONUS)

$(NAME): $(OBJS) $(OBJS_PRINTF)
	$(AR) $(NAME) $(OBJS) $(OBJS_PRINTF)

re: fclean all

clean:
	$(RM) $(OBJS) $(OBJS_BONUS) $(OBJS_PRINTF)

fclean: clean
		$(RM) $(NAME)

.PHONY: all bonus clean fclean re
