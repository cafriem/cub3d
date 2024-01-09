# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/02 22:13:13 by jadithya          #+#    #+#              #
#    Updated: 2024/01/09 17:53:47 by jadithya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = $(SRCDIR)/cub3d.c \
		$(SRCDIR)/DDA.c \
		$(SRCDIR)/keypress.c \
		$(SRCDIR)/error.c \
		$(SRCDIR)/map.c \
		$(SRCDIR)/window_management.c \
		$(SRCDIR)/map_utils.c \
		$(SRCDIR)/map_more.c \
		$(SRCDIR)/map_valid.c \
		$(SRCDIR)/drawing.c \
		$(SRCDIR)/casting.c \

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

OS:= ${shell uname}
ifeq (${OS},Darwin)
	MLXDIR = mlx
	MLXFLG = -framework OpenGL -framework Appkit
	CFLAGS += -D OSX
else
	MLXDIR = mlx-linux
	MLXFLG = -lXext -lX11
	CFLAGS += -D LINUX
 endif

SRCDIR = srcs

OBJDIR = objs

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

LIB = libft/libft.a

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(MLXDIR) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJS)
	make -C libft
	make -C $(MLXDIR)
	$(CC) $(OBJS) $(CFLAGS) -L$(MLXDIR) -lmlx -lm -march=native $(MLXFLG) -o $(NAME) $(LIB)

bonus: 

norm: 
	@python3 -m norminette

clean:
	rm -rf $(OBJS) $(OBJDIR)
	make clean -C libft
	make clean -C $(MLXDIR)

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

valgrind: $(NAME)
	valgrind --leak-check=full ./fdf sample_tests/10-2.fdf
	valgrind --leak-check=full ./fdf sample_tests/10-70.fdf
	valgrind --leak-check=full ./fdf sample_tests/20-60.fdf
	valgrind --leak-check=full ./fdf sample_tests/50-4.fdf
	valgrind --leak-check=full ./fdf sample_tests/100-6.fdf
	valgrind --leak-check=full ./fdf sample_tests/42.fdf
	valgrind --leak-check=full ./fdf sample_tests/amogus.fdf
	valgrind --leak-check=full ./fdf sample_tests/amogus_hd.fdf
	valgrind --leak-check=full ./fdf sample_tests/basictest.fdf
	valgrind --leak-check=full ./fdf sample_tests/elem-col.fdf
	valgrind --leak-check=full ./fdf sample_tests/elem-fract.fdf
	valgrind --leak-check=full ./fdf sample_tests/elem.fdf
	valgrind --leak-check=full ./fdf sample_tests/elem2.fdf
	valgrind --leak-check=full ./fdf sample_tests/julia.fdf
	valgrind --leak-check=full ./fdf sample_tests/mars.fdf
	valgrind --leak-check=full ./fdf sample_tests/pentenegpos.fdf
	valgrind --leak-check=full ./fdf sample_tests/plat.fdf
	valgrind --leak-check=full ./fdf sample_tests/pnp_flat.fdf
	valgrind --leak-check=full ./fdf sample_tests/pylone.fdf
	valgrind --leak-check=full ./fdf sample_tests/pyra.fdf
	valgrind --leak-check=full ./fdf sample_tests/pyramide.fdf
	valgrind --leak-check=full ./fdf sample_tests/t1.fdf
	valgrind --leak-check=full ./fdf sample_tests/t2.fdf
	valgrind --leak-check=full ./fdf sample_tests/zeroes.fdf
	
tests: $(NAME)
	./fdf sample_tests/10-2.fdf
	./fdf sample_tests/10-70.fdf
	./fdf sample_tests/20-60.fdf
	./fdf sample_tests/50-4.fdf
	./fdf sample_tests/100-6.fdf
	./fdf sample_tests/42.fdf
	./fdf sample_tests/amogus.fdf
	./fdf sample_tests/amogus_hd.fdf
	./fdf sample_tests/basictest.fdf
	./fdf sample_tests/elem-col.fdf
	./fdf sample_tests/elem-fract.fdf
	./fdf sample_tests/elem.fdf
	./fdf sample_tests/elem2.fdf
	./fdf sample_tests/julia.fdf
	./fdf sample_tests/mars.fdf
	./fdf sample_tests/pentenegpos.fdf
	./fdf sample_tests/plat.fdf
	./fdf sample_tests/pnp_flat.fdf
	./fdf sample_tests/pylone.fdf
	./fdf sample_tests/pyra.fdf
	./fdf sample_tests/pyramide.fdf
	./fdf sample_tests/t1.fdf
	./fdf sample_tests/t2.fdf
	./fdf sample_tests/zeroes.fdf

fail: $(NAME)
	./fdf sample_tests/empty.fdf
	./fdf sample_tests/test.fdf
	./fdf sample_tests/test.fdf.fdf
	./fdf sample_tests/wrongfilename
	./fdf
	./fdf sample_tests/wrong.fdf

valfail: $(NAME)
	valgrind --leak-check=full ./fdf sample_tests/empty.fdf
	valgrind --leak-check=full ./fdf sample_tests/test.fdf
	valgrind --leak-check=full ./fdf sample_tests/test.fdf.fdf
	valgrind --leak-check=full ./fdf sample_tests/wrongfilename
	valgrind --leak-check=full ./fdf
	valgrind --leak-check=full ./fdf sample_tests/wrong.fdf
	
re: fclean all