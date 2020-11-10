/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:23:03 by wupdegra          #+#    #+#             */
/*   Updated: 2020/08/04 20:05:17 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config_bonus.h>

int		check_map_closed(char **map, t_config *params, int row, int col)
{
	char	ch;
	int		res;

	ch = map[row][col];
	if (ch == ' ' || row < 0 || col < 0 || row >= params->map_h
			|| col >= params->map_w)
		return (1);
	else if (ch == '1' || ch == 'x')
		return (0);
	map[row][col] = 'x';
	res = check_map_closed(map, params, row, col + 1);
	if (!res)
		res = check_map_closed(map, params, row, col - 1);
	if (!res)
		res = check_map_closed(map, params, row + 1, col);
	if (!res)
		res = check_map_closed(map, params, row - 1, col);
	return (res);
}
