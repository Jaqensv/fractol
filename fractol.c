/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:45:36 by mde-lang          #+#    #+#             */
/*   Updated: 2023/06/08 23:42:59 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "fractol.h"
#include "MLX42/include/MLX42/MLX42.h"

void	fractal_init(t_fractal *init)
{
	if (ft_strlen(init->fractal_type) == 10)
		mandelbrot_init(init);
	if (ft_strlen(init->fractal_type) == 5)
		julia_init(init);
}

void	fractal_algo(t_fractal *init)
{
	if (ft_strlen(init->fractal_type) == 10)
		mandelbrot_algo(*init);
	if (ft_strlen(init->fractal_type) == 5)
		julia_algo(*init);
}

int32_t	main(int32_t argc, char **argv)
{
	t_fractal	init;

	init.fractal_type = param_checker(argc, argv[1]);
	init.mlx = mlx_init(WIDTH, HEIGHT, init.fractal_type, false);
	if (!(init.mlx))
		return (EXIT_FAILURE);
	image_init(&init);
	init.index = 0;
	if (argc == 3 && ft_strlen(init.fractal_type) == 5)
	{
		init.index = ft_atoi(argv[2]);
		julia_init(&init);
	}
	else if (argc == 2 && ft_strlen(init.fractal_type) == 5)
		julia_init(&init);
	else
		fractal_init(&init);
	mlx_scroll_hook(init.mlx, scroll, &init);
	mlx_loop_hook(init.mlx, hooks_eq, &init);
	mlx_loop_hook(init.mlx, hooks_x, &init);
	mlx_loop_hook(init.mlx, hooks_y, &init);
	mlx_loop(init.mlx);
	mlx_terminate(init.mlx);
	return (EXIT_SUCCESS);
}

// julia 110000 10 10 10
// segfault julia + grand nombre