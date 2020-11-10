/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 21:20:08 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/02 12:18:45 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static	void	set_tex(t_app *app)
{
	if (app->side <= 1)
		app->tex_wall_x = app->pos_y + app->perpendicular * app->ray_dir_y;
	else
		app->tex_wall_x = app->pos_x + app->perpendicular * app->ray_dir_x;
	app->tex_wall_x -= floor(app->tex_wall_x);
	app->tex_x = (int)(app->tex_wall_x * (double)T_WIDTH);
	if (app->side == 1 || app->side == 2)
		app->tex_x = T_WIDTH - app->tex_x - 1;
	app->tex_step = 1.0 * T_HEIGHT / app->line_height;
	app->tex_pos = (app->draw_start - app->height / 2 + app->line_height / 2)
		* app->tex_step;
}

static	void	perp_draw(t_app *app)
{
	if (app->side <= 1)
		app->perpendicular =
			(app->map_x - app->pos_x + (1 - app->step_x) / 2) / app->ray_dir_x;
	else
		app->perpendicular =
			(app->map_y - app->pos_y + (1 - app->step_y) / 2) / app->ray_dir_y;
	app->line_height = (int)(app->height / app->perpendicular);
	app->draw_start = (-app->line_height / 2 + app->height / 2);
	if (app->draw_start < 0)
		app->draw_start = 0;
	app->draw_end = (app->line_height / 2 + app->height / 2);
	if (app->draw_end >= (int)app->height)
		app->draw_end = app->height - 1;
}

static	void	ray_hit(t_app *app)
{
	app->hit = 0;
	while (app->hit == 0)
	{
		if (app->side_dist_x < app->side_dist_y)
		{
			app->side_dist_x += app->delta_dist_x;
			app->map_x += app->step_x;
			app->side = (app->step_x == -1) ? 0 : 1;
		}
		else
		{
			app->side_dist_y += app->delta_dist_y;
			app->map_y += app->step_y;
			app->side = (app->step_y == -1) ? 2 : 3;
		}
		if (app->cub_map[app->map_x][app->map_y] == '1')
			app->hit = 1;
	}
}

static	void	set_side(t_app *app)
{
	if (app->ray_dir_x < 0)
	{
		app->step_x = -1;
		app->side_dist_x = (app->pos_x - app->map_x) * app->delta_dist_x;
	}
	else
	{
		app->step_x = 1;
		app->side_dist_x = (app->map_x + 1.0 - app->pos_x) * app->delta_dist_x;
	}
	if (app->ray_dir_y < 0)
	{
		app->step_y = -1;
		app->side_dist_y = (app->pos_y - app->map_y) * app->delta_dist_y;
	}
	else
	{
		app->step_y = 1;
		app->side_dist_y = (app->map_y + 1.0 - app->pos_y) * app->delta_dist_y;
	}
}

void			raycasting(t_app *app)
{
	int		x;

	x = 0;
	while (x < (int)app->width)
	{
		app->camera_x = 2 * x / (double)app->width - 1;
		app->ray_dir_x = app->dir_x + app->plane_x * app->camera_x;
		app->ray_dir_y = app->dir_y + app->plane_y * app->camera_x;
		app->map_x = (int)app->pos_x;
		app->map_y = (int)app->pos_y;
		app->delta_dist_x = fabs(1 / app->ray_dir_x);
		app->delta_dist_y = fabs(1 / app->ray_dir_y);
		set_side(app);
		ray_hit(app);
		perp_draw(app);
		app->tex_orient = choose_texture_orient(app->side);
		set_tex(app);
		fill_buffer(app, x);
		app->z_buff[x] = app->perpendicular;
		x++;
	}
}
