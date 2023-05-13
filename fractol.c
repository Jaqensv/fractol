#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "fractol.h"
#include "MLX42/include/MLX42/MLX42.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	fractal_init(t_fractal *init)
{
	if (ft_strlen(init->fractal_type) == 10)
		mandelbrot_init(init);
	if (ft_strlen(init->fractal_type) == 5)
		julia_init(init);
}

int32_t	image_init(t_fractal *init)
{
	if (!(init->mlx = mlx_init(WIDTH, HEIGHT, init->fractal_type, true)))
	{
		//puts(mlx_strerror(mlx_errno)); // remplacer les puts par putstr
		return(EXIT_FAILURE);
	}
	if (!(init->image = mlx_new_image(init->mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(init->mlx);
		//puts(mlx_strerror(mlx_errno)); // remplacer les puts par putstr
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(init->mlx, init->image, 0, 0) == -1)
	{
		mlx_close_window(init->mlx);
		//puts(mlx_strerror(mlx_errno)); // remplacer les puts par putstr
		return(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int32_t	main(int32_t argc, char **argv)
{
	t_fractal	init;

	init.fractal_type = param_checker(argv[1]);
	image_init(&init);
	fractal_init(&init);
	mlx_scroll_hook(init.mlx, scroll, &init);
	mlx_loop_hook(init.mlx, hooks, &init);
	mlx_loop(init.mlx);
	mlx_terminate(init.mlx);
	return (EXIT_SUCCESS);
}
