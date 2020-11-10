/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:53:37 by wupdegra          #+#    #+#             */
/*   Updated: 2020/08/25 00:31:42 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	rotation(t_app *app, bool is_right)
{
	double	tmp_dir;
	double	tmp_plane;
	double	rs;

	rs = (is_right) ? -ROTATION_SPEED : ROTATION_SPEED;
	tmp_dir = app->dir_x;
	tmp_plane = app->plane_x;
	app->dir_x = app->dir_x * cos(rs) - app->dir_y * sin(rs);
	app->dir_y = tmp_dir * sin(rs) + app->dir_y * cos(rs);
	app->plane_x = app->plane_x * cos(rs) - app->plane_y * sin(rs);
	app->plane_y = tmp_plane * sin(rs) + app->plane_y * cos(rs);
}
