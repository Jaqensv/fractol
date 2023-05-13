#include "fractol.h"

void	julia_color(t_fractal init)
{
	if (init.i == init.it_max)
		mlx_put_pixel(init.image, init.x, init.y, 0x96FFFFFF);
	else
		mlx_put_pixel(init.image, init.x, init.y, 0x000000FF);
	return ;
}

void	julia_algo(t_fractal init)
{
	init.y = -1;
	while (++init.y < HEIGHT)
	{
		init.x = -1;
		while (++init.x < WIDTH)
		{
			init.c_r = 0.285;
			init.c_i = 0.01;
			init.z_r = init.x / init.zoom + init.x1;
			init.z_i = init.y / init.zoom + init.y1;
			init.i = 0;
			while (init.z_r * init.z_r + init.z_i * init.z_i < 4 && init.i < init.it_max)
			{
				init.tmp = init.z_r;
				init.z_r = init.z_r * init.z_r - init.z_i * init.z_i + init.c_r;
				init.z_i = 2 * init.z_i * init.tmp + init.c_i;
				init.i++;
				julia_color(init);
			}
		} 
	}
	return ;
}

void	julia_init(t_fractal *init)
{
	init->zoom = 600;
    init->x1 = -1;
	init->x2 = 1;
	init->y1 = -1.2;
	init->y2 = 1.2;
	init->it_max = 100;
	julia_algo(*init);
	return ;
}
