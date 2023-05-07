#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "fractol.h"
#include "MLX42/include/MLX42/MLX42.h"

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
	t_fractal mb;
	t_fractal julia;
	int	x;
	int	y;
	int	i;


	//////////////////////////////////////////////////////
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "fractol", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, WIDTH, HEIGHT)))
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
	mb.x1 = -2.1;
	mb.x2 = 0.6;
	mb.y1 = -1.2;
	mb.y2 = 1.2;
	mb.it_max = 50;
    
    y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			mb.c_r = x / (double)ZOOM + mb.x1;
			mb.c_i = y / (double)ZOOM + mb.y1;
			mb.z_r = 0;
			mb.z_i = 0;
			i = 0;
			while (mb.z_r * mb.z_r + mb.z_i * mb.z_i < 4 && i < mb.it_max)
			{
				mb.tmp = mb.z_r;
				mb.z_r = mb.z_r * mb.z_r - mb.z_i * mb.z_i + mb.c_r;
				mb.z_i = 2 * mb.z_i * mb.tmp + mb.c_i;
				i++;
				if (i == mb.it_max)
					mlx_put_pixel(image, x, y, 0x000000FF);
				else if (i <= mb.it_max / 2 && i > mb.it_max / 3)
					mlx_put_pixel(image, x, y, 0xFFFF00FF);
				else if (i > mb.it_max / 2)
					mlx_put_pixel(image, x, y, 0xFF19FFFF);
				else if (i <= mb.it_max / 3)
					mlx_put_pixel(image, x, y, 0x000000FF);
			}
		} 
	}


	///////// JULIA /////////
	

	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
