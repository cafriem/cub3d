# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/02 22:13:13 by jadithya          #+#    #+#              #
#    Updated: 2024/02/14 15:47:44 by cafriem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

BONUSNAME = bonus_cub3D

SRCS = $(SRCDIR)/cub3d.c \
		$(SRCDIR)/casting.c \
		$(SRCDIR)/DDA_help.c \
		$(SRCDIR)/DDA.c \
		$(SRCDIR)/drawing.c \
		$(SRCDIR)/error.c \
		$(SRCDIR)/free_parsing.c \
		$(SRCDIR)/keypress.c \
		$(SRCDIR)/map_more.c \
		$(SRCDIR)/map_more2.c \
		$(SRCDIR)/map_more3.c \
		$(SRCDIR)/map_utils.c \
		$(SRCDIR)/map_valid.c \
		$(SRCDIR)/map.c \
		$(SRCDIR)/move.c \
		$(SRCDIR)/some_map.c \
		$(SRCDIR)/window_management.c \

BONUS = $(BONUSDIR)/cub3d_bonus.c \
		$(BONUSDIR)/DDA.c \
		$(BONUSDIR)/DDA_help.c \
		$(BONUSDIR)/bonus_move.c \
		$(BONUSDIR)/error.c \
		$(BONUSDIR)/some_map.c \
		$(BONUSDIR)/map.c \
		$(BONUSDIR)/keypress.c \
		$(BONUSDIR)/window_management.c \
		$(BONUSDIR)/map_utils.c \
		$(BONUSDIR)/map_more.c \
		$(BONUSDIR)/map_more2.c \
		$(BONUSDIR)/map_more3.c \
		$(BONUSDIR)/map_valid.c \
		$(BONUSDIR)/drawing.c \
		$(BONUSDIR)/casting.c \
		$(BONUSDIR)/bonus_utils.c \
		$(BONUSDIR)/free_parsing.c \

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3

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

BONUSDIR = bonus_srcs

OBJDIR = objs

B_OBJDIR = bonus_objs

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

BONUS_OBJS = $(BONUS:$(BONUSDIR)/%.c=$(B_OBJDIR)/%.o)

LIB = libft/libft.a

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(MLXDIR) -c $< -o $@

$(B_OBJDIR)/%.o: $(BONUSDIR)/%.c
	$(CC) $(CFLAGS) -I$(MLXDIR) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(B_OBJDIR):
	mkdir -p $(B_OBJDIR)

$(NAME): $(OBJDIR) $(OBJS)
	make -C libft
	make -C $(MLXDIR)
	$(CC) $(OBJS) $(CFLAGS) -L$(MLXDIR) -lmlx -lm -march=native $(MLXFLG) -o $(NAME) $(LIB)

bonus: $(BONUSNAME)

$(BONUSNAME): $(B_OBJDIR) $(BONUS_OBJS)
	make -C libft
	make -C $(MLXDIR)
	$(CC) $(BONUS_OBJS) $(CFLAGS) -L$(MLXDIR) -lmlx -lm -march=native $(MLXFLG) -o $(BONUSNAME) $(LIB)

norm: 
	@python3 -m norminette

clean:
	rm -rf $(OBJS) $(BONUS_OBJS) $(OBJDIR) $(B_OBJDIR)
	make clean -C libft
	make clean -C $(MLXDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUSNAME)
	rm -f libft/libft.a

re: fclean all