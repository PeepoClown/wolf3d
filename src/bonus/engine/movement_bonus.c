/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:07:52 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:17:44 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int		movement(int keycode, t_app *app)
{
	if (keycode == KEY_W || keycode == KEY_ARROW_UP)
		forward(app);
	else if (keycode == KEY_S || keycode == KEY_ARROW_DOWN)
		back(app);
	else if (keycode == KEY_A)
		left(app);
	else if (keycode == KEY_D)
		right(app);
	else if (keycode == KEY_ARROW_LEFT)
		rotation(app, false);
	else if (keycode == KEY_ARROW_RIGHT)
		rotation(app, true);
	else if (keycode == KEY_ESC)
		exit_cub(app);
	return (0);
}

void	forward(t_app *app)
{
	if (app->cub_map[(int)app->pos_x][(int)(app->pos_y + app->dir_y *
		MOVEMENT_SPEED)] == '0')
		app->pos_y += app->dir_y * MOVEMENT_SPEED;
	if (app->cub_map[(int)(app->pos_x + app->dir_x * MOVEMENT_SPEED)]
		[(int)(app->pos_y)] == '0')
		app->pos_x += app->dir_x * MOVEMENT_SPEED;
}

void	back(t_app *app)
{
	if (app->cub_map[(int)app->pos_x][(int)(app->pos_y - app->dir_y *
		MOVEMENT_SPEED)] == '0')
		app->pos_y -= app->dir_y * MOVEMENT_SPEED;
	if (app->cub_map[(int)(app->pos_x - app->dir_x * MOVEMENT_SPEED)]
		[(int)(app->pos_y)] == '0')
		app->pos_x -= app->dir_x * MOVEMENT_SPEED;
}

void	left(t_app *app)
{
	if (app->cub_map[(int)(app->pos_x - app->dir_y * MOVEMENT_SPEED)]
		[(int)(app->pos_y)] == '0')
		app->pos_x -= app->dir_y * MOVEMENT_SPEED;
	if (app->cub_map[(int)(app->pos_x)][(int)(app->pos_y + app->dir_x *
		MOVEMENT_SPEED)] == '0')
		app->pos_y += app->dir_x * MOVEMENT_SPEED;
}

void	right(t_app *app)
{
	if (app->cub_map[(int)(app->pos_x + app->dir_y * MOVEMENT_SPEED)]
		[(int)(app->pos_y)] == '0')
		app->pos_x += app->dir_y * MOVEMENT_SPEED;
	if (app->cub_map[(int)(app->pos_x)][(int)(app->pos_y - app->dir_x *
		MOVEMENT_SPEED)] == '0')
		app->pos_y -= app->dir_x * MOVEMENT_SPEED;
}
