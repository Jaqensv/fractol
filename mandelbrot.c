/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:45:26 by mde-lang          #+#    #+#             */
/*   Updated: 2023/06/07 10:31:04 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_algo(t_fractal init)
{
	init.y = -1;
	while (++init.y < HEIGHT)
	{
		init.x = -1;
		while (++init.x < WIDTH)
		{
			init.c_r = init.x * (init.x2 - init.x1) / WIDTH + init.x1;
			init.c_i = init.y * (init.y2 - init.y1) / HEIGHT + init.y1;
			init.z_r = 0;
			init.z_i = 0;
			init.i = 0;
			while (init.z_r * init.z_r + init.z_i * init.z_i < 4 && init.i < init.it_max)
			{
				init.tmp = init.z_r;
				init.z_r = init.z_r * init.z_r - init.z_i * init.z_i + init.c_r;
				init.z_i = 2 * init.z_i * init.tmp + init.c_i;
				init.i++;
			}
			mlx_put_pixel(init.image, init.x, init.y, ft_color(init));
		}
	}
	return ;
}

void	mandelbrot_init(t_fractal *init)
{
	init->x1 = -2.1;
	init->x2 = 0.6;
	init->y1 = -1.2;
	init->y2 = 1.2;
	init->it_max = 40;
	mandelbrot_algo(*init);
	return ;
}
