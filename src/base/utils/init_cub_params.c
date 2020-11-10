/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:50:45 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:03:07 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_cub_params(t_app *app, t_config *params)
{
	app->mlx.mlx_ptr = NULL;
	app->mlx.win_ptr = NULL;
	app->width = params->resolution.width;
	app->height = params->resolution.height;
	app->texture = NULL;
	app->cub_map = NULL;
	app->buff = NULL;
	app->z_buff = NULL;
	app->sprite = NULL;
	app->s_order = NULL;
	app->f_color = params->floor.hex_v;
	app->c_color = params->celling.hex_v;
	app->map_w = params->map_w;
	app->map_h = params->map_h;
	app->save = params->save;
}
