# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 22:31:55 by vlazuka           #+#    #+#              #
#    Updated: 2019/10/21 22:43:05 by vlazuka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm

SRC = src/*.cpp
CFLAG = -Wall -Wextra -Werror -lncurses

CPP = clang++

O_DIR = objs

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAG) $(SRC) $^ -o $(NAME)

lldb:
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME) -g

clean:
	@rm -rf $(O_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
