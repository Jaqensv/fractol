#include "fractol.h"

void	julia_color(mlx_image_t *image, t_fractal jl, uint32_t x, uint32_t y, int i) /// 5 params ??????
{
	if (i == jl.it_max)
		mlx_put_pixel(image, x, y, 0x96FFFFFF);
	else
		mlx_put_pixel(image, x, y, 0x000000FF);
	return ;
}

void	julia_algo(mlx_image_t *image, t_fractal jl, uint32_t x, uint32_t y)
{
	int	i;

	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			jl.c_r = 0.285;
			jl.c_i = 0.01;
			jl.z_r = x / (double)ZOOM + jl.x1;
			jl.z_i = y / (double)ZOOM + jl.y1;
			i = 0;
			while (jl.z_r * jl.z_r + jl.z_i * jl.z_i < 4 && i < jl.it_max)
			{
				jl.tmp = jl.z_r;
				jl.z_r = jl.z_r * jl.z_r - jl.z_i * jl.z_i + jl.c_r;
				jl.z_i = 2 * jl.z_i * jl.tmp + jl.c_i;
				i++;
				julia_color(image, jl, x, y, i);
			}
		} 
	}
	return ;
}

void	julia_init(mlx_image_t *image)
{
	t_fractal	jl;
	uint32_t	x;
	uint32_t	y;

	x = -1;
	y = -1;
    jl.x1 = -1;
	jl.x2 = 1;
	jl.y1 = -1.2;
	jl.y2 = 1.2;
	jl.it_max = 100;
	julia_algo(image, jl, x, y);
	return ;
}
