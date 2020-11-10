/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_line_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:21:53 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:11:04 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config_bonus.h>

void	validate_map_line(char *line, t_config *params)
{
	size_t	i;

	i = 0;
	while (*(line + i) == ' ' || *(line + i) == '0' || *(line + i) == '1'
			|| *(line + i) == '2' || *(line + i) == 'N' || *(line + i) == 'S'
			|| *(line + i) == 'W' || *(line + i) == 'E')
		i++;
	if (i != ft_strlen(line))
	{
		destroy_params(params);
		ft_error("There is an invalid symbol at a map line!\n");
	}
}
