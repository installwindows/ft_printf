# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 15:46:41 by varnaud           #+#    #+#              #
#    Updated: 2016/11/04 04:45:51 by varnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	  ft_printf.c \
	  handle_field.c \
	  do_conversion.c \
	  s_conversion.c \
	  S_conversion.c \
	  p_conversion.c \
	  d_conversion.c \
	  D_conversion.c \
	  i_conversion.c \
	  o_conversion.c \
	  O_conversion.c \
	  u_conversion.c \
	  U_conversion.c \
	  x_conversion.c \
	  X_conversion.c \
	  c_conversion.c \
	  C_conversion.c

all:
	make -C libft/ fclean && make -C libft/
	gcc $(SRC) -I libft/ -L libft/ -lft
