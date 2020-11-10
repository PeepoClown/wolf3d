/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:21:45 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:11:02 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config_bonus.h>

static	void	validate_map_helper(t_config *params)
{
	char	**tmp_cub_map;

	tmp_cub_map = copy_char_matrix(params->cub_map,
									params->map_h);
	if (!tmp_cub_map)
	{
		destroy_params(params);
		ft_error("Allocation error!\n");
	}
	check_map_borders(tmp_cub_map, params);
	if (check_map_closed(tmp_cub_map, params, params->pos_x, params->pos_y))
	{
		destroy_params(params);
		destroy_char_matrix(tmp_cub_map);
		ft_error("Invalid map allign!\n");
	}
	destroy_char_matrix(tmp_cub_map);
}

void			validate_map(t_config *params)
{
	t_list	*tmp_map;

	if (!params->map)
	{
		destroy_params(params);
		ft_error("Map wasn't found!\n");
	}
	tmp_map = params->map;
	while (tmp_map != NULL)
	{
		validate_map_line(tmp_map->content, params);
		params->map_h++;
		if ((size_t)params->map_w < ft_strlen(tmp_map->content))
			params->map_w = ft_strlen(tmp_map->content);
		tmp_map = tmp_map->next;
	}
	init_cub_map(params);
	complete_cub_map(params);
	check_start_position(params);
	validate_map_helper(params);
}
