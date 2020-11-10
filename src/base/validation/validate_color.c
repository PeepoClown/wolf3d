/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 23:03:44 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:55:48 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config.h>

static	void	check_rgb_values(char *line, t_rgb rgb, t_config *params)
{
	if (rgb.red < 0 || rgb.red > 255
		|| rgb.green < 0 || rgb.green > 255
		|| rgb.blue < 0 || rgb.blue > 255)
	{
		destroy_parse(line, params);
		ft_error("Invalid color param!\n");
	}
}

static	bool	check_rgb_count(char **str_rgb)
{
	int		i;

	i = 0;
	while (str_rgb[i] != NULL)
		i++;
	if (i != 3)
		return (false);
	return (true);
}

void			validate_color(char *line, t_config *params, bool is_floor)
{
	t_rgb	rgb;
	char	*trim_line;
	char	**str_rgb;

	trim_line = ft_delete_ws(line + 1);
	str_rgb = ft_split(trim_line, ',');
	free(trim_line);
	if (!check_rgb_count(str_rgb) || !ft_isnumeric(str_rgb[0])
		|| !ft_isnumeric(str_rgb[1]) || !ft_isnumeric(str_rgb[2]))
	{
		destroy_char_matrix(str_rgb);
		destroy_parse(line, params);
		ft_error("Invalid color param!\n");
	}
	rgb.red = ft_atoi(str_rgb[0]);
	rgb.green = ft_atoi(str_rgb[1]);
	rgb.blue = ft_atoi(str_rgb[2]);
	destroy_char_matrix(str_rgb);
	check_rgb_values(line, rgb, params);
	rgb.hex_v = get_hex_value(rgb.red, rgb.green, rgb.blue);
	rgb.is_set = true;
	if (is_floor == true)
		params->floor = rgb;
	else
		params->celling = rgb;
}
