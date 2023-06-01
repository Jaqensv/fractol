NAME = fractol

SOURCES = fractol.c \
		hooks.c \
		image.c \
		julia.c \
		mandelbrot.c \
		param_checker.c \
		print.c

OBJECTS = $(SOURCES:.c=.o)
BONUS = $(SRC_BONUS:.c=.o)

CC = gcc $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror

all: libft $(NAME) MLX42/build $(NAME)

libft:
	$(MAKE) -C inc_libft

mlx:
	$(shell cmake -S MLX42 -B MLX42/build)
	$(MAKE) -C MLX42/build -j4

$(NAME): $(OBJECTS)
		$(CC) -L inc_libft -lft MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/$$USER/.brew/opt/glfw/lib/" $(OBJECTS) -o $(NAME)

bonus: $(BONUS)
	$(AR) -r $(NAME) $?
	
clean:
		$(MAKE) -C inc_libft clean
		rm -f $(OBJECTS) $(BONUS)

fclean: clean
		$(MAKE) -C inc_libft fclean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test