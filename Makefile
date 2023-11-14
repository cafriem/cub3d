NAME = cube3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Ofast

SRCS =	cube3d.c	\
		DDA.c		\
		keypress.c	\
		error.c
		

OBJS = $(SRCS:.c=.o)

CC = gcc

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

LIBS =	Libft/libft.a

$(NAME): $(OBJS)
	make -C Libft
	make -C MLX
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	make -C MLX clean
	rm -f $(OBJS)
	make -C Libft clean

fclean: clean
	rm -f $(NAME)
	rm -f *.dylib
	make -C Libft fclean

re: fclean all