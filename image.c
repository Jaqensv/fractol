/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:45:15 by mde-lang          #+#    #+#             */
/*   Updated: 2023/06/08 22:48:10 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	ft_color(t_fractal init)
{
	int32_t	color;

	if (init.i == init.it_max)
		color = 255;
	else if (init.i < init.it_max / 2)
		color = init.i * 100005000;
	else
		color = init.i * 154520000;
	return (color);
}

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

int32_t	image_init(t_fractal *init)
{
	init->image = mlx_new_image(init->mlx, WIDTH, HEIGHT);
	if (!(init->image))
	{
		mlx_close_window(init->mlx);
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(init->mlx, init->image, 0, 0) == -1)
	{
		mlx_close_window(init->mlx);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
