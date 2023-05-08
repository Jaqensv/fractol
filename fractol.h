#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include "inc_libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define WIDTH 1200
# define HEIGHT 1200
# define ZOOM 500

typedef struct s_fractal
{
	int		it_max;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	z_r;
	double	z_i;
	double	c_r;
	double	c_i;
	double	tmp;
}					t_fractal;

void	mlx_put_pixel(mlx_image_t* image, uint32_t x, uint32_t y, uint32_t color);
void	mandelbrot_init(mlx_image_t *image);
void	julia_init(mlx_image_t *image);
char	*param_checker(char *argv);
void	did_you_mean_m();
void	did_you_mean_j();
void	param_list();
void	wrong_param();

#endif