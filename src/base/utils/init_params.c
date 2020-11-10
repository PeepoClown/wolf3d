/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 23:06:31 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/02 23:24:38 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config.h>

void	init_config(t_config *params, int argc)
{
	params->n_texture = NULL;
	params->s_texture = NULL;
	params->w_texture = NULL;
	params->e_texture = NULL;
	params->sprite_texture = NULL;
	params->floor.is_set = false;
	params->celling.is_set = false;
	params->resolution.width = 0;
	params->resolution.height = 0;
	params->map_w = 0;
	params->map_h = 0;
	params->map = NULL;
	params->cub_map = NULL;
	params->map_started = false;
	params->save = (argc == 3) ? true : false;
}
