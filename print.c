/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:03:55 by mde-lang          #+#    #+#             */
/*   Updated: 2023/06/08 23:37:14 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	did_you_mean_m(void)
{
	char	*keyword;

	write(2, "\nDid you mean 'mandelbrot' ?\n\n", 31);
	while (ft_strncmp(keyword, "yes", 3) != 0)
	{
		write(2, "Type 'yes' or 'options'\n\n", 25);
		keyword = get_next_line(0);
		if (ft_strncmp(keyword, "yes", 3) == 0
			|| ft_strncmp(keyword, "y", 1) == 0)
			return (free(keyword));
		if (ft_strncmp(keyword, "options", 7) == 0)
		{
			free(keyword);
			param_list();
		}
		free(keyword);
	}
	exit(1);
}

void	did_you_mean_j(void)
{
	char	*keyword;

	write(2, "\nDid you mean 'julia' ?\n\n", 26);
	while (ft_strncmp(keyword, "yes", 3) != 0)
	{
		write(2, "Type 'yes' or 'options'\n\n", 25);
		keyword = get_next_line(0);
		if (ft_strncmp(keyword, "yes", 3) == 0
			|| ft_strncmp(keyword, "y", 1) == 0)
			return (free(keyword));
		if (ft_strncmp(keyword, "options", 7) == 0)
		{
			free(keyword);
			param_list();
		}
		free(keyword);
	}
	exit(1);
}

void	param_list(void)
{
	system("leaks fractol");
	write(2, "******************************\n", 32);
	write(2, "*                            *\n", 32);
	write(2, "*     Available options      *\n", 32);
	write(2, "*                            *\n", 32);
	write(2, "*    - >  mandelbrot  < -    *\n", 32);
	write(2, "*                            *\n", 32);
	write(2, "*    - >    julia     < -    *\n", 32);
	write(2, "*  (julia params : 0 to 11)  *\n", 32);
	write(2, "*                            *\n", 32);
	write(2, "******************************\n", 32);
	exit(1);
}

void	wrong_param(void)
{
	write(2, "******************************\n", 32);
	write(2, "*                            *\n", 32);
	write(2, "*   ⚠ Wrong fractal type ⚠   *\n", 35);
	write(2, "*                            *\n", 32);
	write(2, "*     Available options      *\n", 32);
	write(2, "*                            *\n", 32);
	write(2, "*    - >  mandelbrot  < -    *\n", 32);
	write(2, "*                            *\n", 32);
	write(2, "*    - >    julia     < -    *\n", 32);
	write(2, "*  (julia params : 0 to 11)  *\n", 32);
	write(2, "*                            *\n", 32);
	write(2, "******************************\n", 32);
	exit(1);
}
