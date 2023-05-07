	
    
    
    
    julia.x1 = -1;
	julia.x2 = 1;
	julia.y1 = -1.2;
	julia.y2 = 1.2;
	julia.it_max = 100;
    
    
    y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c_r = 0.285;
			c_i = 0.01;
			z_r = x / (double)ZOOM + julia.x1;
			z_i = y / (double)ZOOM + julia.y1;
			i = 0;
			while (z_r * z_r + z_i * z_i < 4 && i < julia.it_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
				if (i == julia.it_max)
					mlx_put_pixel(image, x, y, 0x96FFFFFF);
				else
					mlx_put_pixel(image, x, y, 0x000000FF);
			}
		} 
	}