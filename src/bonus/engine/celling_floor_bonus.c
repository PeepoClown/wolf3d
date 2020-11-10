/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celling_floor_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:28:54 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:17:11 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static	void	cf_set_tex(t_app *app)
{
	app->cf_cell_x = (int)app->cf_floor_x;
	app->cf_cell_y = (int)app->cf_floor_y;
	app->cf_tex_x = (int)((double)T_WIDTH
		* (app->cf_floor_x - app->cf_cell_x)) & (T_WIDTH - 1);
	app->cf_tex_y = (int)((double)T_HEIGHT
		* (app->cf_floor_y - app->cf_cell_y)) & (T_HEIGHT - 1);
	app->cf_floor_x += app->cf_floor_step_x;
	app->cf_floor_y += app->cf_floor_step_y;
}

static	void	cf_calculation(t_app *app, int y)
{
	app->cf_ray_dir_x0 = app->dir_x - app->plane_x;
	app->cf_ray_dir_x1 = app->dir_x + app->plane_x;
	app->cf_ray_dir_y0 = app->dir_y - app->plane_y;
	app->cf_ray_dir_y1 = app->dir_y + app->plane_y;
	app->cf_pos = y - app->height / 2;
	app->cf_pos_z = app->height / 2;
	app->cf_row_dist = app->cf_pos_z / app->cf_pos;
	app->cf_floor_step_x = app->cf_row_dist * (app->cf_ray_dir_x1
		- app->cf_ray_dir_x0) / app->width;
	app->cf_floor_step_y = app->cf_row_dist * (app->cf_ray_dir_y1
		- app->cf_ray_dir_y0) / app->width;
	app->cf_floor_x = app->pos_x + app->cf_row_dist * app->cf_ray_dir_x0;
	app->cf_floor_y = app->pos_y + app->cf_row_dist * app->cf_ray_dir_y0;
}

void			cf_casting(t_app *app)
{
	int		x;
	int		y;

	y = 0;
	while (y < (int)app->height)
	{
		cf_calculation(app, y);
		x = 0;
		while (x < (int)app->width)
		{
			cf_set_tex(app);
			app->cf_color = dim(app->texture[5][T_WIDTH
				* app->cf_tex_y + app->cf_tex_x], app->cf_row_dist);
			app->buff[y][x] = app->cf_color;
			app->cf_color = dim(app->texture[6][T_WIDTH
				* app->cf_tex_y + app->cf_tex_x], app->cf_row_dist);
			app->buff[app->height - y - 1][x] = app->cf_color;
			x++;
		}
		y++;
	}
}
