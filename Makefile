# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 13:44:44 by tpipi             #+#    #+#              #
#    Updated: 2024/09/02 18:41:07 by tpipi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fun

CC = cc
CFLAGS = -g #-Wall -Wextra -Werror
RM = rm -f

FILES = main.c get_next_line.c get_next_line_utils.c
SRC = $(addprefix src/, $(FILES))
OBJ = $(addprefix obj/, $(FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

obj/%.o : src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re