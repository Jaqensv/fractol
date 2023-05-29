NAME = fractol

SOURCES = fractol.c \
		hooks.c \
		image.c \
		julia.c \
		mandelbrot.c \
		param_checker.c \
		print.c \

OBJECTS = $(SOURCES:.c=.o)
BONUS = $(SRC_BONUS:.c=.o)

CC = gcc $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror

all: MLX42 $(NAME)

mlx:
	$(MAKE) -C MLX42

$(NAME): $(OBJECTS)
		$(CC) -L MLX42 $(OBJECTS) -o $(NAME)

bonus: $(BONUS)
	$(AR) -r $(NAME) $?
	
clean:
		rm -f $(OBJECTS) $(BONUS)
		$(MAKE) -C MLX42 clean

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C MLX42 fclean

re: fclean all

.PHONY: all clean fclean re test