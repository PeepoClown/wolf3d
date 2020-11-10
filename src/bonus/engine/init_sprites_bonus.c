/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 10:04:56 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:17:40 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	count_sprites(t_app *app, t_config *params)
{
	int		i;
	int		j;

	i = 0;
	app->sprite_count = 0;
	while (i < params->map_h)
	{
		j = 0;
		while (j < params->map_w)
		{
			if (params->cub_map[i][j] == '2')
				app->sprite_count++;
			j++;
		}
		i++;
	}
}

void	set_sprites(t_app *app, t_config *params)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < params->map_h)
	{
		j = 0;
		while (j < params->map_w)
		{
			if (params->cub_map[i][j] == '2')
			{
				app->sprite[k].x = i + 0.5;
				app->sprite[k].y = j + 0.5;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	init_sprites(t_app *app, t_config *params)
{
	count_sprites(app, params);
	if (!(app->sprite = (t_sprite*)malloc(sizeof(t_sprite)
		* app->sprite_count)))
	{
		destroy(app, params);
		ft_error("Allocation error!\n");
	}
	set_sprites(app, params);
	if (!(app->z_buff = (double*)malloc(sizeof(double) * app->width)))
	{
		destroy(app, params);
		ft_error("Allocation error!\n");
	}
	if (!(app->s_order = (int*)malloc(sizeof(int) * app->sprite_count)))
	{
		destroy(app, params);
		ft_error("Allocation error!\n");
	}
}
