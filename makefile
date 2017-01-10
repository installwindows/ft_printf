# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 15:46:41 by varnaud           #+#    #+#              #
#    Updated: 2017/01/09 15:58:22 by varnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	  handle_num.c \
	  handle_string.c \
	  handle_wcstr.c \
	  do_conversion.c \
	  s_conversion.c \
	  ls_conversion.c \
	  p_conversion.c \
	  d_conversion.c \
	  ld_conversion.c \
	  i_conversion.c \
	  o_conversion.c \
	  lo_conversion.c \
	  u_conversion.c \
	  lu_conversion.c \
	  x_conversion.c \
	  cx_conversion.c \
	  c_conversion.c \
	  lc_conversion.c

OBJ = $(SRC:.c=.o)
OBJLIB = libft/*.o

all:
	make -C libft/ fclean && make -C libft/
	gcc -c $(SRC) -Ilibft/
	ar rc $(NAME) $(OBJ) $(OBJLIB)
	ranlib $(NAME)
test:
	gcc main.c $(SRC) -Ilibft/ -Llibft/ -lft
