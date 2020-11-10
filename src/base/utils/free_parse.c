/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 23:36:16 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:55:12 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config.h>

static	void	destroy_content(void *content)
{
	free(content);
}

static	void	destroy_params_helper(t_config *params)
{
	if (params->map)
		ft_lstclear(&(params->map), &destroy_content);
	destroy_char_matrix(params->cub_map);
	free(params);
}

void			destroy_params(t_config *params)
{
	if (params->n_texture)
		free(params->n_texture);
	if (params->s_texture)
		free(params->s_texture);
	if (params->w_texture)
		free(params->w_texture);
	if (params->e_texture)
		free(params->e_texture);
	if (params->sprite_texture)
		free(params->sprite_texture);
	destroy_params_helper(params);
}

void			destroy_parse(char *line, t_config *params)
{
	free(line);
	while (get_next_line(params->fd, &line) > 0)
		free(line);
	free(line);
	destroy_params(params);
}
