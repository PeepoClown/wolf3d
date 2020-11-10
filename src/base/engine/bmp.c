/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 19:21:26 by wupdegra          #+#    #+#             */
/*   Updated: 2020/08/31 20:36:28 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static	void	init_bmp(t_app *app)
{
	app->bmp.signature[0] = 'B';
	app->bmp.signature[1] = 'M';
	app->bmp.file_size = 54 + (4 * app->width * app->height);
	app->bmp.reserved = 0;
	app->bmp.data_offset = 14;
	app->bmp.header_size = 40;
	app->bmp.width = (int)app->width;
	app->bmp.height = (int)app->height;
	app->bmp.planes = 1;
	app->bmp.bpp = 32;
	app->bmp.compression = 0;
	app->bmp.img_size = 0;
	app->bmp.x_ppm = 0;
	app->bmp.y_ppm = 0;
	app->bmp.color_used = 256;
	app->bmp.color_important = 0;
}

static	void	write_screen_header(t_app *app, int fd)
{
	init_bmp(app);
	write(fd, &(app->bmp.signature), sizeof(app->bmp.signature));
	write(fd, &(app->bmp.file_size), sizeof(app->bmp.file_size));
	write(fd, &(app->bmp.reserved), sizeof(app->bmp.reserved));
	write(fd, &(app->bmp.data_offset), sizeof(app->bmp.data_offset));
	write(fd, &(app->bmp.header_size), sizeof(app->bmp.header_size));
	write(fd, &(app->bmp.width), sizeof(app->bmp.width));
	write(fd, &(app->bmp.height), sizeof(app->bmp.height));
	write(fd, &(app->bmp.planes), sizeof(app->bmp.planes));
	write(fd, &(app->bmp.bpp), sizeof(app->bmp.bpp));
	write(fd, &(app->bmp.compression), sizeof(app->bmp.compression));
	write(fd, &(app->bmp.img_size), sizeof(app->bmp.img_size));
	write(fd, &(app->bmp.x_ppm), sizeof(app->bmp.x_ppm));
	write(fd, &(app->bmp.y_ppm), sizeof(app->bmp.y_ppm));
	write(fd, &(app->bmp.color_used), sizeof(app->bmp.color_used));
	write(fd, &(app->bmp.color_important), sizeof(app->bmp.color_important));
}

static	void	write_screen_pixel_data(t_app *app, int fd)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	while (y < (int)app->height)
	{
		x = 0;
		while (x < (int)app->width)
		{
			color = app->buff[(int)app->height - y - 1][x];
			app->map_w = color + fd;
			write(fd, &color, 4);
			x++;
		}
		y++;
	}
}

void			save_screen(t_app *app)
{
	int		fd;

	raycasting(app);
	spritecasting(app);
	fd = open("screen.bmp", O_WRONLY | O_TRUNC | O_CREAT,
		S_IRWXU | S_IWGRP | S_IWOTH);
	if (fd < 0)
	{
		destroy_app(app);
		ft_error("Can't to create screenshot file!\n");
	}
	write_screen_header(app, fd);
	write_screen_pixel_data(app, fd);
	close(fd);
	destroy_app(app);
	exit(0);
}
