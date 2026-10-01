CC	= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS = 	main.c cheapest_nbr.c get_pos.c get_target_number_a.c get_target_number_b.c\
		rotate_push.c stack_load.c struct_values.c turksort.c rotate_calc.c\
		rotations/push.c rotations/rev_rotate.c rotations/rotate.c rotations/swap_12.c\
		check_is_valid.c

OBJ	= $(SRCS:.c=.o)


NAME = push_swap


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
