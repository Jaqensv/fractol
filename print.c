#include "fractol.h"

void    did_you_mean_m()
{
    write(2, "\nDid you mean 'mandelbrot' ?\n\n", 31);
    exit(1);
}

void    did_you_mean_j()
{
    write(2, "\nDid you mean 'julia' ?\n\n", 26);
    exit(1);
}

void    param_list()
{
    write(2, "\n⚠ Wrong fractal type ⚠\n\n", 30);
    write(2, "Try the following options :\n\n", 30);
    write(2, "-> mandelbrot <-\n\n", 19);
    write(2, "-> julia <-\n\n", 14);
    exit(1);
}
