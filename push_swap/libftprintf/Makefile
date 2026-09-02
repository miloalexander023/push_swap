CC	= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= printf.c utils.c

OBJ	= printf.o utils.o

NAME = libftprintf.a
LIBFT_DIR = ../ft_libft
LIBFT   = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all re clean fclean
