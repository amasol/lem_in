NAME = lem-in
#FLAGS = -Wall -Wextra -Werror
LIB = libft.a
SRC = main.c parsing.c error.c \
      save_room.c arr_len.c parsing_help.c \
      comparison.c error_help.c save_room_link.c \
      save_map.c algorithm.c ft_list_size.c output.c swap.c\
      list_reverse.c output_help.c algorithm_help.c \
      algorithm_help_two.c

HEADERS = ./lem_in.h
OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	echo "-----------------------------------"
	echo "lem_in is ready to work"
	@ cd ./libft && make && mv $(LIB) ..
	@ gcc -g $(OBJ) $(LIB) $(FLAGS) -o $(NAME)
%.o: %.c $(HEADERS)
	@ gcc $(FLAGS) -c $<
clean:
	echo "-----------------------------------"
	echo "Objects files are removed"
	@ /bin/rm -rf $(OBJ)
	@ cd ./libft && make clean
fclean: clean
	echo "-----------------------------------"
	echo "lem_in is deleted"
	@ /bin/rm -f $(NAME)
	@ /bin/rm -f $(LIB)
	@ cd ./libft && make fclean
re: fclean all