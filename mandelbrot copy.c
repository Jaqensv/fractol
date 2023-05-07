	mb.x1 = -2.1;
	mb.x2 = 0.6;
	mb.y1 = -1.2;
	mb.y2 = 1.2;
	mb.it_max = 50;
    
    y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c_r = x / (double)ZOOM + mb.x1;
			c_i = y / (double)ZOOM + mb.y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while (z_r * z_r + z_i * z_i < 4 && i < mb.it_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
				if (i == mb.it_max)
					mlx_put_pixel(image, x, y, 0x000000FF);
				else if (i <= mb.it_max / 2 && i > mb.it_max / 3)
					mlx_put_pixel(image, x, y, 0xFFFF00FF);
				else if (i > mb.it_max / 2)
					mlx_put_pixel(image, x, y, 0xFF19FFFF);
				else if (i <= mb.it_max / 3)
					mlx_put_pixel(image, x, y, 0x000000FF);
			}
		} 
	}
