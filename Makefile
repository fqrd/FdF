# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 14:30:44 by fcaquard          #+#    #+#              #
#    Updated: 2021/08/26 15:17:51 by fcaquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# gcc src/*.c -L./libs/minilibx-linux -lmlx -lXext -lX11 -lbsd -L./libs/_libft -lft -lm && ./a.out

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_FOLDER = ./src/

PATH_LIBS = ./lib/
LMLX = $(PATH_LIBS)minilibx-linux
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

OBJS = $(SRCS:.c=.o)

all :  makemlx makelft
	$(CC) $(CFLAGS) $(SRCS) -L$(LMLX) -lmlx -lXext -lX11 -lbsd -lm -L$(LFT) -lft -o $(NAME)

clean:
	rm -f $(SRC_FOLDER)*.o

fclean: clean
	rm -f ./$(NAME)

re: cleanlibs fclean all

makelft: 
	cd $(LFT) && $(MAKE)
	
makemlx:
	cd $(LMLX) && $(MAKE)

cleanlibs: cleanlft cleanmlx

cleanmlx:
	cd $(LMLX) && $(MAKE) clean

cleanlft:
	cd $(LFT) && $(MAKE) fclean

.PHONY: clean fclean re all makemlx makelft cleanlibs cleanlft cleanmlx