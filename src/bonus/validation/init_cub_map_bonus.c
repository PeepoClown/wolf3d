/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:22:06 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:10:48 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config_bonus.h>

void	init_cub_map(t_config *params)
{
	int		i;
	t_list	*tmp_map;

	if (!(params->cub_map = (char**)malloc(sizeof(char*)
			* (params->map_h + 1))))
	{
		destroy_params(params);
		ft_error("Allocation error!\n");
	}
	i = 0;
	tmp_map = params->map;
	while (i < params->map_h && tmp_map)
	{
		params->cub_map[i] = ft_strdup(tmp_map->content);
		if (!params->cub_map[i])
		{
			destroy_params(params);
			ft_error("Allocation error!\n");
		}
		tmp_map = tmp_map->next;
		i++;
	}
	params->cub_map[i] = NULL;
}
