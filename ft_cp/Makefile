NAME = ft_cp

CC = cc

FLAGS = -Wall -Werror -Wextra -g

SRC = ft_cp.c src/input_error.c src/single_file_copy.c src/copy_to_dir.c

OBJ = $(SRC:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
