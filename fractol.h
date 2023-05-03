#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>

# define ZOOM 100
# define IMG_X 600
# define IMG_Y 600

typedef struct s_itmax
{
    int it_max;
}                   t_itmax;

typedef struct s_fractal
{
    double x1;
    double x2;
    double y1;
    double y2;
}					t_fractal;

void mlx_put_pixel(mlx_image_t* image, uint32_t x, uint32_t y, uint32_t color);

#endif