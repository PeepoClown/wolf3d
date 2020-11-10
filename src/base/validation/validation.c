/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 23:08:17 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:54:38 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config.h>

void	validation(const char *filename, t_config *params)
{
	char	*line;

	params->fd = open(filename, O_RDONLY);
	while (get_next_line(params->fd, &line) > 0)
	{
		validate_line(line, params);
		free(line);
	}
	validate_line(line, params);
	free(line);
	if (!params->n_texture || !params->s_texture || !params->w_texture
			|| !params->e_texture || !params->sprite_texture
			|| !params->resolution.width || !params->resolution.width
			|| !params->floor.is_set || !params->celling.is_set)
	{
		destroy_params(params);
		ft_error("Not all params are set!\n");
	}
	validate_map(params);
	close(params->fd);
}
