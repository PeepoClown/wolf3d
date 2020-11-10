/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 17:11:28 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:12:19 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static	void	destroy_app_helper(t_app *app)
{
	int		i;

	i = 0;
	if (app->texture != NULL)
	{
		while (i < 7)
		{
			if (app->texture[i] != NULL)
				free(app->texture[i]);
			i++;
		}
		free(app->texture);
	}
	i = 0;
	if (app->buff != NULL)
	{
		while (i < (int)app->height)
		{
			if (app->buff[i] != NULL)
				free(app->buff[i]);
			i++;
		}
		free(app->buff);
	}
}

void			destroy_app(t_app *app)
{
	destroy_app_helper(app);
	if (app->sprite != NULL)
		free(app->sprite);
	if (app->z_buff != NULL)
		free(app->z_buff);
	if (app->s_order != NULL)
		free(app->s_order);
	destroy_char_matrix(app->cub_map);
	mlx_destroy_image(app->mlx.mlx_ptr, app->mlx.img.img_ptr);
	if (app->mlx.win_ptr != NULL)
		mlx_destroy_window(app->mlx.mlx_ptr, app->mlx.win_ptr);
	free(app->mlx.mlx_ptr);
	free(app);
}

void			destroy(t_app *app, t_config *params)
{
	destroy_params(params);
	destroy_app(app);
}
