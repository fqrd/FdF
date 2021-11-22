# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 14:30:44 by fcaquard          #+#    #+#              #
#    Updated: 2021/08/26 16:49:51 by fcaquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_FOLDER = ./src/
PATH_LIBS = ./lib/
LMLX = $(PATH_LIBS)minilibx-linux
LMLX_MACOS = $(PATH_LIBS)minilibx_macos
LMLX_MACOS_SIERRA = $(PATH_LIBS)minilibx_mms_20191025_beta
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

$(NAME):  mlxmacos makelibft
	$(CC) $(CFLAGS) $(SRCS) -L$(LFT) -lft $(LMLX_MACOS)/libmlx.a -lm -framework OpenGL -framework AppKit -o $(NAME)

linux :  mlxlinux makelibft
	$(CC) $(CFLAGS) $(SRCS) -L$(LMLX) -lmlx -lXext -lX11 -lbsd -lm -L$(LFT) -lft -o $(NAME)

sierra: mlxsierra makelibft
	$(CC) $(CFLAGS) $(SRCS) -L$(LFT) -lft $(LMLX_MACOS)/libmlx.a -lm -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(SRC_FOLDER)*.o

fclean: clean
	rm -f ./$(NAME)

re: cleanlibft fclean all

mlxlinux:
	cd $(LMLX) && $(MAKE)

mlxmacos:
	cd $(LMLX_MACOS) && $(MAKE)

mlxsierra:
	cd $(LMLX_MACOS_SIERRA) && $(MAKE)

makelibft: 
	cd $(LFT) && $(MAKE)

cleanlibs: cleanlibft cleanmacos cleansierra cleanlinux 

cleanlinux:
	cd $(LMLX) && $(MAKE) clean

cleanmacos:
	cd $(LMLX_MACOS) && $(MAKE) clean

cleansierra:
	cd $(LMLX_MACOS_SIERRA) && $(MAKE) clean

cleanlibft:
	cd $(LFT) && $(MAKE) fclean

.PHONY: clean fclean re all mlxlinux mlxmacos mlxsierra makelibft \
		cleanlibs cleanlinux cleanmacos cleansierra cleanlibft