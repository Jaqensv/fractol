#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include "inc_libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "inc_gnl/get_next_line.h"

# define WIDTH 800
# define HEIGHT 800

typedef struct s_fractal
{	
	int32_t			x;
	int32_t			y;
	mlx_image_t		*image;
	void			*mlx;
	char			*fractal_type;
	int				i;
	int				it_max;
	double 			zoom;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			z_r;
	double			z_i;
	double			c_r;
	double			c_i;
	double			tmp;
	int				index;
}					t_fractal;

char		*param_checker(int32_t argc, char *argv);
void		mlx_put_pixel(mlx_image_t* image, uint32_t x, uint32_t y, uint32_t color);
void		mandelbrot_init(t_fractal *init);
void		julia_init(t_fractal *init);
void		did_you_mean_m();
void		did_you_mean_j();
void		param_list();
void		wrong_param();
void		hooks_eq(void *param);
void		hooks_x(void *param);
void		hooks_y(void *param);
void		mandelbrot_algo(t_fractal init);
void		julia_algo(t_fractal init);
void		scroll(double xdelta, double ydelta, void* param);
void		fractal_init(t_fractal *init);
void		coefficient_julia(t_fractal *init);
void		fractal_algo(t_fractal *init);
void		redimension_image(t_fractal *init);
int32_t		image_init(t_fractal *init);
int32_t		ft_color(t_fractal init);
t_fractal	*init_modifier_zoom(t_fractal *init);
t_fractal	*init_modifier_dezoom(t_fractal *init);

#endif