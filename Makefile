NAME = so_long

SOURCES = so_long.c mlx_xpm.c mlx_string_put.c mlx_rgb.c mlx_png.c font.c \

OBJECTS = $(SOURCES:.c=.o)
BONUS = $(SRC_BONUS:.c=.o)

CC = gcc $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror -g

all: mlx $(NAME)

mlx:
	$(MAKE) -C mlx

$(NAME): $(OBJECTS)
		$(CC) -L mlx $(OBJECTS) -o $(NAME)

bonus: $(BONUS)
	$(AR) -r $(NAME) $?
	
clean:
		rm -f $(OBJECTS) $(BONUS)
		$(MAKE) -C mlx clean

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C mlx fclean

re: fclean all

.PHONY: all clean fclean re test