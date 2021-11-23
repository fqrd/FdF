# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 14:30:44 by fcaquard          #+#    #+#              #
#    Updated: 2021/11/23 15:53:53 by fcaquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_FOLDER = ./src/
PATH_LIBS = ./lib/
LMLX_LINUX = $(PATH_LIBS)minilibx-linux
LMLX_MACOS = $(PATH_LIBS)minilibx_macos
FRAMEWORKS = -framework OpenGL -framework AppKit

LFT = $(PATH_LIBS)libft
NAME = fdf

SRCS = \
	$(SRC_FOLDER)actions.c		\
	$(SRC_FOLDER)bresenham.c	\
	$(SRC_FOLDER)draw.c			\
	$(SRC_FOLDER)line_utils.c	\
	$(SRC_FOLDER)main.c			\
	$(SRC_FOLDER)map_utils.c	\
	$(SRC_FOLDER)navigation.c	\
	$(SRC_FOLDER)parse.c		\
	$(SRC_FOLDER)views.c		\
	$(SRC_FOLDER)clear.c		\

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	
$(NAME):	$(OBJS) makelibft mlxmacos
	$(CC) $(CFLAGS) $(OBJS) -L$(LFT) -lft $(LMLX_MACOS)/libmlx.a -lm $(FRAMEWORKS) -o $(NAME)

linux:	$(OBJS) makelibft mlxlinux
	$(CC) $(CFLAGS) $(OBJS) -L$(LFT) -lft -L$(LMLX_LINUX) -lmlx -lXext -lX11 -lbsd -lm  -o $(NAME)

clean:
	rm -f $(SRC_FOLDER)*.o

fclean: clean
	rm -f ./$(NAME)

# reset compilation on different OS (default macos)

re: reset cleanmacos all

relinux: reset cleanlinux linux

reset: cleanlibft fclean

# compiles & clean libft

makelibft: 
	cd $(LFT) && $(MAKE)

cleanlibft:
	cd $(LFT) && $(MAKE) fclean

# compiles mlx libs on different OS

mlxlinux:
	cd $(LMLX) && $(MAKE)

mlxmacos:
	cd $(LMLX_MACOS) && $(MAKE)

# clean mlx on different OS

cleanlinux: cleanlibft fclean
	cd $(LMLX) && $(MAKE) clean

cleanmacos: cleanlibft fclean
	cd $(LMLX_MACOS) && $(MAKE) clean

.PHONY: clean fclean re all mlxlinux mlxmacos mlxsierra makelibft \
		cleanlinux cleanmacos cleansierra cleanlibft