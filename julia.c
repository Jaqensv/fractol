/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:45:19 by mde-lang          #+#    #+#             */
/*   Updated: 2023/06/08 22:45:32 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_algo(t_fractal init)
{
	init.y = -1;
	while (++init.y < HEIGHT)
	{
		init.x = -1;
		while (++init.x < WIDTH)
		{
			coefficient_julia(&init);
			init.z_r = init.x * (init.x2 - init.x1) / WIDTH + init.x1;
			init.z_i = init.y * (init.y2 - init.y1) / HEIGHT + init.y1;
			init.i = 0;
			while (init.z_r * init.z_r + init.z_i * init.z_i < 4
				&& init.i < init.it_max)
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

void	coefficient_julia(t_fractal *init)
{
	init->coefficient_r[0] = 0.285;
	init->coefficient_r[1] = 0.27;
	init->coefficient_r[2] = 0.27;
	init->coefficient_r[3] = -0.51;
	init->coefficient_r[4] = -0.68;
	init->coefficient_r[5] = -0.75;
	init->coefficient_r[6] = -1.03;
	init->coefficient_r[7] = -0.51;
	init->coefficient_r[8] = -0.13;
	init->coefficient_r[9] = -0.06;
	init->coefficient_r[10] = 0.36;
	init->coefficient_i[0] = 0.01;
	init->coefficient_i[1] = 0;
	init->coefficient_i[2] = -0.53;
	init->coefficient_i[3] = -0.56;
	init->coefficient_i[4] = -0.18;
	init->coefficient_i[5] = -0.12;
	init->coefficient_i[6] = 0;
	init->coefficient_i[7] = 0.46;
	init->coefficient_i[8] = 0.77;
	init->coefficient_i[9] = 0.68;
	init->coefficient_i[10] = 0.46;
	init->c_r = init->coefficient_r[init->index];
	init->c_i = init->coefficient_i[init->index];
	return ;
}

void	julia_init(t_fractal *init)
{
	init->zoom = 280;
	init->x1 = -1;
	init->x2 = 1;
	init->y1 = -1.2;
	init->y2 = 1.2;
	init->it_max = 80;
	julia_algo(*init);
	return ;
}
