CC	= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS = 	main.c cheapest_nbr.c get_pos.c get_target_number_a.c get_target_number_b.c\
		rotate_push.c stack_load.c struct_values.c turksort.c rotate_calc.c\
		rotations/push.c rotations/rev_rotate.c rotations/rotate.c rotations/swap_12.c

OBJ	= $(SRCS:.c=.o)



NAME = push_swap
LIBFT_DIR = ft_libft
LIBFT   = $(LIBFT_DIR)/libft.a
PRINTF_DIR = libftprintf
PRINTF   = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all re clean fclean
