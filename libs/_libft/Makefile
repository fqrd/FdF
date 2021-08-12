# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 18:10:36 by fcaquard          #+#    #+#              #
#    Updated: 2021/08/06 16:40:43 by fcaquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC_FOLDER = ./src/
GNL_SRC_FOLDER = ./src/get_next_line/
PRINTF_SRC_FOLDER = ./src/ft_printf/

SRCS = \
	$(SRC_FOLDER)ft_isspace.c	\
	$(SRC_FOLDER)ft_isalnum.c	\
	$(SRC_FOLDER)ft_isalpha.c	\
	$(SRC_FOLDER)ft_isascii.c	\
	$(SRC_FOLDER)ft_isdigit.c	\
	$(SRC_FOLDER)ft_isprint.c	\
	$(SRC_FOLDER)ft_isspace.c	\
	$(SRC_FOLDER)ft_tolower.c	\
	$(SRC_FOLDER)ft_toupper.c	\
	$(SRC_FOLDER)ft_atoi.c		\
	$(SRC_FOLDER)ft_itoa.c		\
	$(SRC_FOLDER)ft_putchar.c	\
	$(SRC_FOLDER)ft_putnbr.c	\
	$(SRC_FOLDER)ft_putstr.c	\
	$(SRC_FOLDER)ft_strlen.c	\
	$(SRC_FOLDER)ft_intlen.c	\
	$(SRC_FOLDER)ft_power.c		\
	$(SRC_FOLDER)ft_countchar.c	\
	$(SRC_FOLDER)ft_strtrim.c	\
	$(SRC_FOLDER)ft_substr.c	\
	$(SRC_FOLDER)ft_strlcpy.c	\
	$(SRC_FOLDER)ft_split.c		\
	$(SRC_FOLDER)ft_calloc.c	\

SRCS_GNL = \
	$(GNL_SRC_FOLDER)get_next_line.c		\
	$(GNL_SRC_FOLDER)get_next_line_utils.c	\

SRCS_PRINTF = \
	$(PRINTF_SRC_FOLDER)ft_printf_csdiuXx.c		\
	$(PRINTF_SRC_FOLDER)ft_printf_utils.c		\
	$(PRINTF_SRC_FOLDER)ft_printf.c				\



OBJS = $(SRCS:.c=.o) $(SRCS_GNL:.c=.o) $(SRCS_PRINTF:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	ar rs $(NAME) $(OBJS)

clean:
	rm -f $(SRC_FOLDER)*.o $(PRINTF_SRC_FOLDER)*o $(GNL_SRC_FOLDER)*o

fclean: clean
	rm -f ./$(NAME)

re: fclean all

.PHONY: clean fclean re all