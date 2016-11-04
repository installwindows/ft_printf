# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 15:46:41 by varnaud           #+#    #+#              #
#    Updated: 2016/11/03 22:46:37 by varnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	  ft_printf.c \
	  s_conversion.c \
	  handle_field.c \
	  do_conversion.c

all:
	make -C libft/ fclean && make -C libft/
	gcc $(SRC) -I libft/ -L libft/ -lft
