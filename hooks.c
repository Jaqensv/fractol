/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:16:06 by mde-lang          #+#    #+#             */
/*   Updated: 2023/06/06 12:44:07 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal	*init_modifier_zoom(t_fractal *init)
{
	double	tmp;

	tmp = init->x1;
	init->x1 = init->x1 - (init->x1 - init->x2) * (1 - 0.9) / 2;
	init->x2 = init->x2 - (init->x2 - tmp) * (1 - 0.9) / 2;
	tmp = init->y1;
	init->y1 = init->y1 - (init->y1 - init->y2) * (1 - 0.9) / 2;
	init->y2 = init->y2 - (init->y2 - tmp) * (1 - 0.9) / 2;
	init->it_max += 1;
	return (init);
}

t_fractal	*init_modifier_dezoom(t_fractal *init)
{
	double	tmp;
	
	tmp = init->x1;
	init->x1 = init->x1 - (init->x1 - init->x2) * (1 - 1.1) / 2;
	init->x2 = init->x2 - (init->x2 - tmp) * (1 - 1.1) / 2;
	tmp = init->y1;
	init->y1 = init->y1 - (init->y1 - init->y2) * (1 - 1.1) / 2;
	init->y2 = init->y2 - (init->y2 - tmp) * (1 - 1.1) / 2;
	init->it_max -= 1;
	return (init);
}

void	scroll(double xdelta, double ydelta, void* param)
{
	t_fractal	*init;

	(void)xdelta;
	init = (t_fractal *)param;
	if (ydelta > 0)
	{
		init_modifier_zoom(init);
		fractal_algo(init);
	}
	else if (ydelta < 0)
	{
		init_modifier_dezoom(init);
		fractal_algo(init);
	}
}

void	hooks(void *param)
{
	double		move;
	t_fractal	*init;

	init = (t_fractal *)param;
	if (mlx_is_key_down(init->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(init->mlx);
	
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
	if (mlx_is_key_down(init->mlx, MLX_KEY_1))
	{
		init_modifier_zoom(init);
		fractal_algo(init);
	}
	if (mlx_is_key_down(init->mlx, MLX_KEY_2))
	{
		init_modifier_dezoom(init);
		fractal_algo(init);
	}
}
