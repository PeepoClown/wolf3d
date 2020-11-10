/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 19:48:24 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:17:51 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void			get_sprite_dist(t_app *app)
{
	int		i;

	i = 0;
	while (i < (int)app->sprite_count)
	{
		app->sprite[i].dist = (app->pos_x - app->sprite[i].x) * (app->pos_x
			- app->sprite[i].x) + (app->pos_y - app->sprite[i].y)
			* (app->pos_y - app->sprite[i].y);
		app->s_order[i] = i;
		i++;
	}
}

void			sort_sprites(t_app *app)
{
	int		i;
	int		j;
	int		tmp_order;
	double	tmp_dist;

	i = 0;
	while (i < (int)app->sprite_count - 1)
	{
		j = 0;
		while (j < ((int)app->sprite_count - i - 1))
		{
			if (app->sprite[j].dist < app->sprite[j + 1].dist)
			{
				tmp_dist = app->sprite[j + 1].dist;
				app->sprite[j + 1].dist = app->sprite[j].dist;
				app->sprite[j].dist = tmp_dist;
				tmp_order = app->s_order[j + 1];
				app->s_order[j + 1] = app->s_order[j];
				app->s_order[j] = tmp_order;
			}
			j++;
		}
		i++;
	}
}
