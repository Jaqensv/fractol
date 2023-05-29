#include "fractol.h"

char	*mandelbrot_checker(char *argv)
{
	int		i;
	char	*mandelbrot;

	i = 0;
	mandelbrot = "mandelbrot";
	while (argv && argv[i] && (argv[i] == mandelbrot[i] || argv[i] == mandelbrot[i] - 32))
		i++;
	if (i == ft_strlen(mandelbrot))
		return ("Mandelbrot");
	else if (i > 3)
		did_you_mean_m();
	else
		wrong_param();
	return("Mandelbrot");
}

char	*julia_checker(char *argv)
{
	int		i;
	char	*julia;

	i = 0;
	julia = "julia";
	while (argv && argv[i] && argv[i] == julia[i] || argv[i] == julia[i] - 32)
		i++;
	if (i == ft_strlen(julia))
		return ("Julia");
	else if (i > 2)
		did_you_mean_j();
	else
		wrong_param();
	return ("Julia");
}

char	*param_checker(int32_t argc, char *argv)
{
	char	*fractal_type;

	if (argc > 3)
		wrong_param();
	if (argv[0] == 'm' || argv[0] == 'M')
		fractal_type = mandelbrot_checker(argv);
	else if (argv[0] == 'j' || argv[0] == 'J')
		fractal_type = julia_checker(argv);
	else
		wrong_param();
	return (fractal_type);
}
