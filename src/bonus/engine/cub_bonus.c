/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:01:45 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:17:17 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int		cub(t_app *app)
{
	cf_casting(app);
	raycasting(app);
	spritecasting(app);
	drawing(app);
	mlx_put_image_to_window(app->mlx.mlx_ptr, app->mlx.win_ptr,
								app->mlx.img.img_ptr, 0, 0);
	return (0);
}
