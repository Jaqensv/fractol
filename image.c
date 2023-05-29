#include "fractol.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	image_init(t_fractal *init)
{
	if (!(init->image = mlx_new_image(init->mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(init->mlx);
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(init->mlx, init->image, 0, 0) == -1)
	{
		mlx_close_window(init->mlx);
		return(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
