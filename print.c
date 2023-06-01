#include "fractol.h"

void    did_you_mean_m()
{
    char    keyword[7];

    write(2, "\nDid you mean 'mandelbrot' ?\n\n", 31);
    while (strcmp(keyword, "yes") != 0)
    {
        write(2, "Type 'yes' or 'options'\n\n", 25);
        scanf("%s", keyword);
        if (strcmp(keyword, "yes") == 0 || strcmp(keyword, "y") == 0)
            return ;
        if (strcmp(keyword, "options") == 0)
            param_list();
    }
    exit(1);
}

void    did_you_mean_j()
{
    char    keyword[7];

    write(2, "\nDid you mean 'julia' ?\n\n", 26);
    while (strcmp(keyword, "yes") != 0)
    {
        write(2, "Type 'yes' or 'options'\n\n", 25);
        scanf("%s", keyword);
        if (strcmp(keyword, "yes") == 0 || strcmp(keyword, "y") == 0)
            return ;
        if (strcmp(keyword, "options") == 0)
            param_list();
    }
    exit(1);
}

void    param_list()
{
    write(2, "******************************\n", 32);
    write(2, "*                            *\n", 32);
    write(2, "*     Available options      *\n", 32);
    write(2, "*                            *\n", 32);
    write(2, "*    - >  mandelbrot  < -    *\n", 32);
    write(2, "*                            *\n", 32);
    write(2, "*    - >    julia     < -    *\n", 32);
    write(2, "*                            *\n", 32);
    write(2, "******************************\n", 32);
    exit(1);
}

void    wrong_param()
{
    write(2, "******************************\n", 32);
    write(2, "*                            *\n", 32);
    write(2, "*   ⚠ Wrong fractal type ⚠  *\n", 35);
    write(2, "*                            *\n", 32);
    write(2, "*     Available options      *\n", 32);
    write(2, "*                            *\n", 32);
    write(2, "*    - >  mandelbrot  < -    *\n", 32);
    write(2, "*                            *\n", 32);
    write(2, "*    - >    julia     < -    *\n", 32);
    write(2, "*                            *\n", 32);
    write(2, "******************************\n", 32);
    exit(1);
}
