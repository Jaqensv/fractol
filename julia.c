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
			coefficient_julia(&init); 
			//0.285;
			//0.01;
			init.z_r = init.x / init.zoom + init.x1;
			init.z_i = init.y / init.zoom + init.y1;
			init.i = 0;
			while (init.z_r * init.z_r + init.z_i * init.z_i < 4 && init.i < init.it_max)
			{
				init.tmp = init.z_r;
				init.z_r = init.z_r * init.z_r - init.z_i * init.z_i + init.c_r;
				init.z_i = 2 * init.z_i * init.tmp + init.c_i;
				init.i++;
			}
			julia_color(init);
		} 
	}
	return ;
}

void	coefficient_julia(t_fractal *init)
{
	double coefficient_r[11] = {0.285, 0.27, 0.27, -0.51, -0.68, -0.75, -1.03, -0.51, -0.13, -0.06, 0.36};
	double coefficient_i[11] = {0.01, 0, -0.53, -0.56, -0.18, -0.12, 0, 0.46, 0.77, 0.68, 0.46};

	init->c_r = coefficient_r[init->index];
	init->c_i = coefficient_i[init->index];
	return ;
}

void	julia_init(t_fractal *init)
{
	init->zoom = 280;
    init->x1 = -1;
	init->x2 = 1;
	init->y1 = -1.2;
	init->y2 = 1.2;
	init->it_max = 80;
	julia_algo(*init);
	return ;
}
