/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:58:03 by mde-lang          #+#    #+#             */
/*   Updated: 2023/06/09 13:27:52 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include "inc_libft/libft.h"
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
	double			zoom;
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
	double			coefficient_r[11];
	double			coefficient_i[11];
}					t_fractal;

char		*param_checker(int32_t argc, char *argv);
void		mlx_put_pixel(mlx_image_t *image, uint32_t x,
				uint32_t y, uint32_t color);
void		mandelbrot_init(t_fractal *init);
void		julia_init(t_fractal *init);
void		did_you_mean_m(void);
void		did_you_mean_j(void);
void		param_list(void);
void		wrong_param(void);
void		hooks_eq(void *param);
void		hooks_x(void *param);
void		hooks_y(void *param);
void		mandelbrot_algo(t_fractal init);
void		julia_algo(t_fractal init);
void		scroll(double xdelta, double ydelta, void *param);
void		coefficient_julia(t_fractal *init);
void		fractal_algo(t_fractal *init);
void		fractal_init(t_fractal *init, int argc, char **argv);
int32_t		image_init(t_fractal *init);
int32_t		ft_color(t_fractal init);
t_fractal	*init_modifier_zoom(t_fractal *init);
t_fractal	*init_modifier_dezoom(t_fractal *init);

#endif