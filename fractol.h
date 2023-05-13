#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include "inc_libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define WIDTH 1200
# define HEIGHT 1200

typedef struct s_fractal
{
	int32_t		x;
	int32_t		y;
	int			i;
	int			it_max;
	int			zoom_x;
	int			zoom_y;
	double		zoom;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		z_r;
	double		z_i;
	double		c_r;
	double		c_i;
	double		tmp;
	void		*image;
	void		*mlx;
	char		*fractal_type;
}					t_fractal;

// typedef struct s_data
// {
// 	struct s_fractal	init;
// }					t_data;

char	*param_checker(char *argv);
void	mlx_put_pixel(mlx_image_t* image, uint32_t x, uint32_t y, uint32_t color);
void	mandelbrot_init(t_fractal *init);
void	julia_init(t_fractal *init);
void	did_you_mean_m();
void	did_you_mean_j();
void	param_list();
void	wrong_param();
void	hooks(void *param);
void	mandelbrot_algo(t_fractal init);
void	julia_algo(t_fractal init);
void	scroll(double xdelta, double ydelta, void* param);
void	fractal_init(t_fractal *init);
int32_t	image_init(t_fractal *init);

#endif