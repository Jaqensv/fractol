#include "fractol.h"

void	mandelbrot_color(t_fractal init)
{
	if (init.i == init.it_max)
		mlx_put_pixel(init.image, init.x, init.y, 0x000000FF);
	else if (init.i <= init.it_max / 2 && init.i > init.it_max / 3)
		mlx_put_pixel(init.image, init.x, init.y, 0xFFFF00FF);
	else if (init.i > init.it_max / 2)
		mlx_put_pixel(init.image, init.x, init.y, 0xFF19FFFF);
	else if (init.i <= init.it_max / 3)
		mlx_put_pixel(init.image, init.x, init.y, 0xFFFFFFFF);
	return ;
}

void	mandelbrot_algo(t_fractal init)
{
	init.y = -1;
	while (++init.y < HEIGHT)
	{
		init.x = -1;
		while (++init.x < WIDTH)
		{
			init.c_r = init.x * (init.x2 - init.x1) / WIDTH + init.x1;
			init.c_i = init.y * (init.y2 - init.y1) / HEIGHT + init.y1;
			init.z_r = 0;
			init.z_i = 0;
			init.i = 0;
			while (init.z_r * init.z_r + init.z_i * init.z_i < 4 && init.i < init.it_max)
			{
				init.tmp = init.z_r;
				init.z_r = init.z_r * init.z_r - init.z_i * init.z_i + init.c_r;
				init.z_i = 2 * init.z_i * init.tmp + init.c_i;
				init.i++;
			}
			mandelbrot_color(init);
		}
	}
	return ;
}

void	mandelbrot_init(t_fractal *init)
{
	init->x1 = -2.1;
	init->x2 = 0.6;
	init->y1 = -1.2;
	init->y2 = 1.2;
	init->it_max = 40;
	mandelbrot_algo(*init);
	return ;
}
