#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "fractol.h"
#include "MLX42/include/MLX42/MLX42.h"

#define WIDTH 512
#define HEIGHT 512

static mlx_image_t* image;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

int32_t main(int32_t argc, const char* argv[])
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 600, 600)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	t_itmax it_max;
	t_fractal	mandel;

	it_max.it_max = 50;
	mandel.x1 = -2.1;
	mandel.x2 = 0.6;
	mandel.y1 = -1.2;
	mandel.y2 = 1.2;

	int x = 0;
	int y = 0;
	int c_r = x / ZOOM + mandel.x1;
	int c_i = y / ZOOM + mandel.y1;
	int z_r = 0;
	int z_i = 0;
	int i = 0;
	double tmp = z_r;

	while ((z_r * z_r + z_i * z_i) < 4 && i < it_max.it_max)
	{
		z_r = (z_r * z_r) - (z_i * z_i + c_r);
		z_i = 2 * (z_i * tmp) + c_i;
		if (i == it_max.it_max)
			mlx_put_pixel(image, x, y, 0xFF0000FF);
		i = i + 1;
	}
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
 //l’ensemble de Mandelbrot est toujours compris entre -2.1 et 0.6 sur l’axe des abscisse et entre -1.2 et 1.2 sur l’axe des ordonnées.