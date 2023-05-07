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
    write(2, "******************************\n", 32);
    write(2, "*                            *\n", 32);
    write(2, "*   ⚠ Wrong fractal type ⚠   *\n", 36);
    write(2, "*                            *\n", 32);
    write(2, "* Try the following options  *\n", 32);
    write(2, "*                            *\n", 32);
    write(2, "*    - >  mandelbrot  < -    *\n", 32);
    write(2, "*                            *\n", 32);
    write(2, "*    - >    julia     < -    *\n", 32);
    write(2, "*                            *\n", 32);
    write(2, "******************************\n", 32);
    exit(1);
}
