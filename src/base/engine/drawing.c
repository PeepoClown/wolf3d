/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 21:04:34 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 23:41:15 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	fill_buffer(t_app *app, int x)
{
	int y;

	y = 0;
	while (y < app->draw_start)
	{
		app->buff[y][x] = app->c_color;
		y++;
	}
	while (y < app->draw_end)
	{
		app->tex_y = (int)app->tex_pos & (T_HEIGHT - 1);
		app->tex_pos += app->tex_step;
		app->tex_color = app->texture[app->tex_orient]
			[T_HEIGHT * app->tex_y + app->tex_x];
		app->buff[y][x] = app->tex_color;
		y++;
	}
	while (y < (int)app->height - 1)
	{
		app->buff[y][x] = app->f_color;
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
