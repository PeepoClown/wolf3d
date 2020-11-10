/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 15:52:40 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:12:52 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config_bonus.h>

void	init_config(t_config *params, int argc)
{
	params->n_texture = NULL;
	params->s_texture = NULL;
	params->w_texture = NULL;
	params->e_texture = NULL;
	params->sprite_texture = NULL;
	params->floor_texture = NULL;
	params->celling_texture = NULL;
	params->resolution.width = 0;
	params->resolution.height = 0;
	params->map_w = 0;
	params->map_h = 0;
	params->map = NULL;
	params->cub_map = NULL;
	params->map_started = false;
	params->save = (argc == 3) ? true : false;
}
