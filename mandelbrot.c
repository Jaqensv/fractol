#include "fractol.h"

void	mandelbrot_color(mlx_image_t *image, t_fractal mb, uint32_t x, uint32_t y, int i) /// 5 params ??????
{
	if (i == mb.it_max)
		mlx_put_pixel(image, x, y, 0x000000FF);
	else if (i <= mb.it_max / 2 && i > mb.it_max / 3)
		mlx_put_pixel(image, x, y, 0xFFFF00FF);
	else if (i > mb.it_max / 2)
		mlx_put_pixel(image, x, y, 0xFF19FFFF);
	else if (i <= mb.it_max / 3)
		mlx_put_pixel(image, x, y, 0x000000FF);
	return ;
}

void	mandelbrot_algo(mlx_image_t *image, t_fractal mb, uint32_t x, uint32_t y)
{
	int	i;

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
				mandelbrot_color(image, mb, x, y, i);
			}
		} 
	}
	return ;
}

void	mandelbrot_init(mlx_image_t *image)
{
	t_fractal	mb;
	uint32_t	x;
	uint32_t	y;

	x = -1;
	y = -1;
	mb.x1 = -2.1;
	mb.x2 = 0.6;
	mb.y1 = -1.2;
	mb.y2 = 1.2;
	mb.it_max = 50;
	mandelbrot_algo(image, mb, x, y);
	return ;
}

