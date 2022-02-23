# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchae <wchae@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 23:37:42 by wchae             #+#    #+#              #
#    Updated: 2022/02/24 00:03:15 by wchae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $(OBJS)

clean :
	rm -rf $(OBJS) $(OBJS_B)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

test :
	gcc -g $(SRCS) main.c -I ./

.PHONY: clean fclean re all test