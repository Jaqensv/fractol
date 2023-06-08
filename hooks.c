/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:40:04 by mde-lang          #+#    #+#             */
/*   Updated: 2023/06/08 23:08:48 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scroll(double xdelta, double ydelta, void *param)
{
	t_fractal	*init;
	static int	i = 0;

	(void)xdelta;
	init = (t_fractal *)param;
	if (ydelta > 0)
	{
		init_modifier_zoom(init);
		i++;
		fractal_algo(init);
	}
	else if (ydelta < 0 && i > -5)
	{
		init_modifier_dezoom(init);
		i--;
		fractal_algo(init);
	}
}

void	hooks_eq(void *param)
{
	t_fractal	*init;

	init = (t_fractal *)param;
	if (mlx_is_key_down(init->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(init->mlx);
	if (mlx_is_key_down(init->mlx, MLX_KEY_E))
	{
		if (init->index < 10)
		{
			init->index++;
			mlx_delete_image(init->mlx, init->image);
			image_init(init);
			fractal_algo(init);
		}
	}
	if (mlx_is_key_down(init->mlx, MLX_KEY_Q))
	{
		if (init->index > 0)
		{
			init->index--;
			mlx_delete_image(init->mlx, init->image);
			image_init(init);
			fractal_algo(init);
		}
	}
}

void	hooks_x(void *param)
{
	double		move;
	t_fractal	*init;

	init = (t_fractal *)param;
	if (mlx_is_key_down(init->mlx, MLX_KEY_RIGHT))
	{
		move = (init->x2 - init->x1) * 0.1;
		init->x1 += move;
		init->x2 += move;
		fractal_algo(init);
	}
	if (mlx_is_key_down(init->mlx, MLX_KEY_LEFT))
	{
		move = (init->x2 - init->x1) * 0.1;
		init->x1 -= move;
		init->x2 -= move;
		fractal_algo(init);
	}
}

void	hooks_y(void *param)
{
	double		move;
	t_fractal	*init;

	init = (t_fractal *)param;
	if (mlx_is_key_down(init->mlx, MLX_KEY_UP))
	{
		move = (init->y2 - init->y1) * 0.1;
		init->y1 -= move;
		init->y2 -= move;
		fractal_algo(init);
	}
	if (mlx_is_key_down(init->mlx, MLX_KEY_DOWN))
	{
		move = (init->y2 - init->y1) * 0.1;
		init->y1 += move;
		init->y2 += move;
		fractal_algo(init);
	}
}
