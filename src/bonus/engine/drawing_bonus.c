/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 21:04:34 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:17:19 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int		dim(int color, double dist)
{
	t_rgb	rgb;
	double	dark;
	int		red;
	int		green;
	int		blue;

	dark = DARK / dist;
	rgb.red = (int)(color / pow(2, 16)) & 255;
	rgb.green = (int)(color / pow(2, 8)) & 255;
	rgb.blue = color & 255;
	red = (int)(rgb.red * dark);
	red = (red > rgb.red) ? rgb.red : red;
	green = (int)(rgb.green * dark);
	green = (green > rgb.green) ? rgb.green : green;
	blue = (int)(rgb.blue * dark);
	blue = (blue > rgb.blue) ? rgb.blue : blue;
	return (get_hex_value(red, green, blue));
}

void	fill_buffer(t_app *app, int x)
{
	int y;

	y = app->draw_start;
	while (y < app->draw_end)
	{
		app->tex_y = (int)app->tex_pos & (T_HEIGHT - 1);
		app->tex_pos += app->tex_step;
		app->tex_color = dim(app->texture[app->tex_orient]
			[T_HEIGHT * app->tex_y + app->tex_x], app->perpendicular);
		app->buff[y][x] = app->tex_color;
		y++;
	}
}

void	drawing(t_app *app)
{
	int		x;
	int		y;

	y = 0;
	while (y < (int)app->height)
	{
		x = 0;
		while (x < (int)app->width)
		{
			app->mlx.img.data[app->width * y + x] = app->buff[y][x];
			x++;
		}
		y++;
	}
}
