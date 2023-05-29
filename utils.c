#include "fractol.h"

void redimension_image(t_fractal *init)
{
    // Déterminer la largeur et la hauteur de la zone visible
    double largeur = init->x2 - init->x1;
    double hauteur = init->y2 - init->y1;

    // Calculer les facteurs d'échelle inverses
    double scaleX = largeur / WIDTH;
    double scaleY = hauteur / HEIGHT;

    // Calculer les nouvelles dimensions de l'image
    uint32_t nwidth = largeur / scaleX;
    uint32_t nheight = hauteur / scaleY;

    // Redimensionner l'image
    mlx_resize_image(init->image, nwidth, nheight);
}
