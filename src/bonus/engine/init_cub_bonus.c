/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:28:55 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:17:30 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	init_cub(t_app *app, t_config *params)
{
	init_cub_params(app, params);
	init_mlx(app);
	init_pos(app, params);
	init_textures(app, params);
	init_sprites(app, params);
	init_buffer(app, params);
	app->cub_map = copy_char_matrix(params->cub_map, params->map_h);
	destroy_params(params);
}
