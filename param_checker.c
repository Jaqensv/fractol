#include "fractol.h"

char   *mandelbrot_checker(char *argv)
{
    int i;
    char    *mandelbrot;

    i = 0;
    mandelbrot = "mandelbrot";
    while (argv[i] == mandelbrot[i] || argv[i] == mandelbrot[i] - 32)
        i++;
    if (i - 1 == ft_strlen(mandelbrot))
        return ("Mandelbrot");
    else if (i > 4)
        did_you_mean_m();
    else
        param_list();
    exit(1);
}

char   *julia_checker(char *argv)
{
    int i;
    char    *julia;

    i = 0;
    julia = "julia";
    while (argv[i] == julia[i] || argv[i] == julia[i] - 32)
        i++;
    if (i - 1 == ft_strlen(julia))
        return ("Julia");
    else if (i > 2)
        did_you_mean_j();
    else
        param_list();
    exit(1);
}

char   *param_checker(char *argv)
{
    char    *fractal_type;

    if (argv[0] == 'm' || argv[0] == 'M')
        fractal_type = mandelbrot_checker(argv);
    else if (argv[0] == 'j' || argv[0] == 'J')
        fractal_type = julia_checker(argv);
    else
        param_list();
    return (fractal_type);
}
