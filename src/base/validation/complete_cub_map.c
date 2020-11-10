/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_cub_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:22:18 by wupdegra          #+#    #+#             */
/*   Updated: 2020/08/28 12:06:07 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config.h>

static	char	*add_spaces_padding(char *line, int count)
{
	size_t	i;
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * (ft_strlen(line) + count + 1))))
		return (NULL);
	i = 0;
	while (i < ft_strlen(line))
	{
		res[i] = line[i];
		i++;
	}
	while (i < ft_strlen(line) + count)
	{
		res[i] = ' ';
		i++;
	}
	res[i] = '\0';
	return (res);
}

void			complete_cub_map(t_config *params)
{
	int		i;
	int		len_diff;
	char	*tmp;

	i = 0;
	while (i < params->map_h)
	{
		len_diff = params->map_w - ft_strlen(params->cub_map[i]);
		if (len_diff > 0)
		{
			tmp = params->cub_map[i];
			params->cub_map[i] = add_spaces_padding(params->cub_map[i],
														len_diff);
			free(tmp);
			if (!params->cub_map[i])
			{
				destroy_params(params);
				ft_error("Allocation error!\n");
			}
		}
		i++;
	}
}
