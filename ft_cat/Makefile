# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvaz-da- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/18 16:51:26 by rvaz-da-          #+#    #+#              #
#    Updated: 2025/08/19 09:56:18 by rvaz-da-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat.a

SRC = handle_errors.c main.c ft_cat.c scan_and_print.c

INCLUDE = .

OBJ = $(SRC:.c=.o)

EXEC = ft_cat

RM = rm -f

all: $(NAME) $(EXEC)

%.o: %.c
	cc $(FLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(EXEC): $(OBJ)
	cc $(FLAGS) $(OBJ) -o  $(EXEC)

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
