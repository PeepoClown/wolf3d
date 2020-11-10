/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start_position_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:22:25 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:10:39 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config_bonus.h>

static	void	set_position(t_config *params, int *alone_flag, int i, int j)
{
	*alone_flag = *alone_flag + 1;
	params->pos_x = i;
	params->pos_y = j;
	params->orient = params->cub_map[i][j];
	params->cub_map[params->pos_x][params->pos_y] = '0';
}

void			check_start_position(t_config *params)
{
	int		i;
	int		j;
	int		alone_flag;

	i = 0;
	alone_flag = 0;
	while (i < params->map_h)
	{
		j = 0;
		while (j < params->map_w)
		{
			if (params->cub_map[i][j] == 'N' || params->cub_map[i][j] == 'S'
				|| params->cub_map[i][j] == 'W' || params->cub_map[i][j] == 'E')
				set_position(params, &alone_flag, i, j);
			j++;
		}
		i++;
	}
	if (alone_flag != 1)
	{
		destroy_params(params);
		ft_error("There is not one start positions at the map!\n");
	}
}
