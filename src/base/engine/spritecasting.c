/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritecasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 19:28:30 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 18:57:09 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static	void	calc_sprites(t_app *app, int i)
{
	double v_mode;

	v_mode = 0;
	app->sprite_ray_x = app->sprite[app->s_order[i]].x - app->pos_x;
	app->sprite_ray_y = app->sprite[app->s_order[i]].y - app->pos_y;
	app->sprite_inv_det = 1.0 / (app->plane_x * app->dir_y - app->dir_x
		* app->plane_y);
	app->sprite_ray_trans_x = app->sprite_inv_det * (app->dir_y
		* app->sprite_ray_x - app->dir_x * app->sprite_ray_y);
	app->sprite_ray_trans_y = app->sprite_inv_det * (-app->plane_y
		* app->sprite_ray_x + app->plane_x * app->sprite_ray_y);
	app->sprite_ray_screen_x = (int)((app->width / 2) * (1
		+ app->sprite_ray_trans_x / app->sprite_ray_trans_y));
	app->sprite_ray_v_screen = (int)(v_mode / app->sprite_ray_trans_y);
}

static	void	get_sprite_height(t_app *app)
{
	int		v_div;

	v_div = 1;
	app->sprite_ray_height = abs((int)(app->height
		/ app->sprite_ray_trans_y)) / v_div;
	app->sprite_ray_draw_start_y = -app->sprite_ray_height / 2
		+ app->height / 2 + app->sprite_ray_v_screen;
	if (app->sprite_ray_draw_start_y < 0)
		app->sprite_ray_draw_start_y = 0;
	app->sprite_ray_draw_end_y = app->sprite_ray_height / 2
		+ app->height / 2 + app->sprite_ray_v_screen;
	if (app->sprite_ray_draw_end_y >= (int)app->height)
		app->sprite_ray_draw_end_y = app->height - 1;
}

static	void	get_sprite_width(t_app *app)
{
	int		u_div;

	u_div = 1;
	app->sprite_ray_width = abs((int)(app->height
		/ app->sprite_ray_trans_y)) / u_div;
	app->sprite_ray_draw_start_x = -app->sprite_ray_width / 2
		+ app->sprite_ray_screen_x;
	if (app->sprite_ray_draw_start_x < 0)
		app->sprite_ray_draw_start_x = 0;
	app->sprite_ray_draw_end_x = app->sprite_ray_width / 2
		+ app->sprite_ray_screen_x;
	if (app->sprite_ray_draw_end_x >= (int)app->width)
		app->sprite_ray_draw_end_x = app->width - 1;
}

static	void	insert_sprite(t_app *app, int line)
{
	int		draw;
	int		y;
	int		color;

	app->sprite_ray_tex_x = (int)((256 * (line - (-app->sprite_ray_width / 2
		+ app->sprite_ray_screen_x)) * T_WIDTH / app->sprite_ray_width) / 256);
	if (app->sprite_ray_trans_y > 0 && line > 0 && line < (int)app->width
		&& app->sprite_ray_trans_y < app->z_buff[line])
	{
		y = app->sprite_ray_draw_start_y;
		while (y < app->sprite_ray_draw_end_y)
		{
			draw = (y - app->sprite_ray_v_screen) * 256 - app->height * 128
				+ app->sprite_ray_height * 128;
			app->sprite_ray_tex_y = (draw * T_HEIGHT / app->sprite_ray_height)
				/ 256;
			color = app->texture[4][T_WIDTH * app->sprite_ray_tex_y
				+ app->sprite_ray_tex_x];
			if (color != 0)
				app->buff[y][line] = color;
			y++;
		}
	}
}

void			spritecasting(t_app *app)
{
	int		i;
	int		line;

	get_sprite_dist(app);
	sort_sprites(app);
	i = 0;
	while (i < (int)app->sprite_count)
	{
		calc_sprites(app, i);
		get_sprite_height(app);
		get_sprite_width(app);
		line = app->sprite_ray_draw_start_x;
		while (line < app->sprite_ray_draw_end_x)
		{
			insert_sprite(app, line);
			line++;
		}
		i++;
	}
}
