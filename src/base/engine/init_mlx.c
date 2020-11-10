/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 19:30:59 by wupdegra          #+#    #+#             */
/*   Updated: 2020/08/31 19:52:48 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_mlx(t_app *app)
{
	app->mlx.mlx_ptr = mlx_init();
	app->mlx.img.img_ptr = mlx_new_image(app->mlx.mlx_ptr, app->width,
		app->height);
	app->mlx.img.data = (int*)mlx_get_data_addr(app->mlx.img.img_ptr,
		&(app->mlx.img.bit_per_pix), &(app->mlx.img.size_line),
		&(app->mlx.img.endian));
}
