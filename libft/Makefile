NAME = libft.a

SRCS =ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strlen.c		\
		ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strncmp.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_strnstr.c	\
		ft_atoi.c		\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_itoa.c		\
		ft_split.c		\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_double_pointer_counter.c\
		ft_strhex.c		\
		ft_power.c		\
		ft_freesplit.c	\
		ft_strdupfree.c	\
		ft_strcmp.c

GNLSRC = gnl/get_next_line_bonus.c\
		gnl/get_next_line_utils_bonus.c\

GNLOBJS = $(GNLSRC:.c=.o)

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJS) $(GNLOBJS)
	ar rc $(NAME) $(OBJS) $(GNLOBJS)

all: $(NAME)

clean:
	rm -f $(OBJS) $(GNLOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all