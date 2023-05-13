#include "fractol.h"

t_fractal	*init_modifier_zoom(t_fractal *init)
{
	init->zoom += 50;
	init->it_max += 10;
	init->x1 += 0.15;
	// init->y2 = 0;
	return (init);
}

t_fractal	*init_modifier_dezoom(t_fractal *init)
{
	init->zoom -= 50;
	init->it_max -= 10;
	//init->x1 += 0.15;
	// init->y2 = 0;
	return (init);
}

void	scroll(double xdelta, double ydelta, void* param)
{
	t_fractal	*init;

	init = (t_fractal *)param;
	if (ydelta > 0)
	{
		//mlx_get_mouse_pos(init->mlx, &init->zoom_x, &init->zoom_y);
		//printf("x%d, y%d\n", init->x, init->y);
		init_modifier_zoom(init);
		if (ft_strlen(init->fractal_type) == 10)
			mandelbrot_algo(*init);
		if (ft_strlen(init->fractal_type) == 5)
			julia_algo(*init);
	}
	else if (ydelta < 0)
		init_modifier_dezoom(init);
		if (ft_strlen(init->fractal_type) == 10)
			mandelbrot_algo(*init);
		if (ft_strlen(init->fractal_type) == 5)
			julia_algo(*init);;
}

void	hooks(void *param)
{
	t_fractal *init;

	init = (t_fractal *)param;
	if (mlx_is_key_down(init->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(init->mlx);
}
