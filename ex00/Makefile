# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yumi <yumi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/02 16:59:58 by yu-chen           #+#    #+#              #
#    Updated: 2024/08/05 15:53:05 by yumi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Fixed.cpp

INC = Fixed.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
