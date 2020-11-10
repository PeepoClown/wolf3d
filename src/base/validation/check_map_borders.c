/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:22:37 by wupdegra          #+#    #+#             */
/*   Updated: 2020/08/04 20:05:20 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config.h>

static	void	put_error_map_border(char **map, t_config *params)
{
	destroy_params(params);
	destroy_char_matrix(map);
	ft_error("Invalid map borders!\n");
}

void			check_map_borders(char **map, t_config *params)
{
	int		i;
	char	*tmp;
	bool	error;

	i = 0;
	error = false;
	while (i < params->map_h)
	{
		tmp = ft_delete_ws(map[i]);
		if (i == 0 || i == (params->map_h - 1))
		{
			if (!ft_contains_only(tmp, '1'))
				error = true;
		}
		else
		{
			if (*tmp != '1' || *(tmp + ft_strlen(tmp) - 1) != '1')
				error = true;
		}
		free(tmp);
		i++;
	}
	if (error)
		put_error_map_border(map, params);
}
