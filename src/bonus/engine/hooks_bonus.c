/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 15:56:49 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:17:23 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	hooks(t_app *app)
{
	mlx_hook(app->mlx.win_ptr, 2, 1L << 0, movement, app);
	mlx_hook(app->mlx.win_ptr, 17, 1L << 17, exit_cub, app);
	mlx_loop_hook(app->mlx.mlx_ptr, cub, app);
	mlx_loop(app->mlx.mlx_ptr);
}
