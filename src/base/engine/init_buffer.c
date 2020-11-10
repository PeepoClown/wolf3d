/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 16:40:34 by wupdegra          #+#    #+#             */
/*   Updated: 2020/08/30 16:46:44 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static	void	preset_buffer(t_app *app)
{
	int		i;
	int		j;

	i = 0;
	while (i < (int)app->height)
	{
		j = 0;
		while (j < (int)app->width)
		{
			app->buff[i][j] = 0;
			j++;
		}
		i++;
	}
}

void			init_buffer(t_app *app, t_config *params)
{
	int		i;

	if (!(app->buff = (int**)malloc(sizeof(int*) * app->height)))
	{
		destroy(app, params);
		ft_error("Allocation error!\n");
	}
	i = 0;
	while (i < (int)app->height)
	{
		if (!(app->buff[i] = (int*)malloc(sizeof(int) * app->width)))
		{
			destroy(app, params);
			ft_error("Allocation error!\n");
		}
		i++;
	}
	preset_buffer(app);
}
