/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:01:37 by wupdegra          #+#    #+#             */
/*   Updated: 2020/08/31 22:24:44 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static	void	init_orient_helper(t_app *app)
{
	app->dir_x = 0;
	app->dir_y = 1;
	app->plane_x = 0.66;
	app->plane_y = 0;
}

static	void	init_orient(t_app *app, t_orient orient)
{
	if (orient == North)
	{
		app->dir_x = -1;
		app->dir_y = 0;
		app->plane_x = 0;
		app->plane_y = 0.66;
	}
	else if (orient == South)
	{
		app->dir_x = 1;
		app->dir_y = 0;
		app->plane_x = 0;
		app->plane_y = -0.66;
	}
	else if (orient == West)
	{
		app->dir_x = 0;
		app->dir_y = -1;
		app->plane_x = -0.66;
		app->plane_y = 0;
	}
	else if (orient == East)
		init_orient_helper(app);
}

void			init_pos(t_app *app, t_config *params)
{
	app->pos_x = params->pos_x + 0.5;
	app->pos_y = params->pos_y + 0.5;
	if (params->orient == 'N')
		init_orient(app, North);
	else if (params->orient == 'S')
		init_orient(app, South);
	else if (params->orient == 'W')
		init_orient(app, West);
	else if (params->orient == 'E')
		init_orient(app, East);
}
