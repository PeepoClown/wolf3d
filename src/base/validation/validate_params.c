/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 23:09:04 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/02 23:11:23 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config.h>

static	void	invalid_param(char *line, t_config *params)
{
	destroy_parse(line, params);
	ft_error("Invalid param!\n");
}

void			validate_params(char *line, t_config *params)
{
	int		fst_char;

	fst_char = 0;
	while (*(line + fst_char) == 32)
		fst_char++;
	if (*(line + fst_char) == 'R')
		validate_resolution(line, params);
	else if (*(line + fst_char) == 'N' && *(line + fst_char + 1) == 'O')
		validate_texture(line, params, 2);
	else if (*(line + fst_char) == 'S' && *(line + fst_char + 1) == 'O')
		validate_texture(line, params, 2);
	else if (*(line + fst_char) == 'W' && *(line + fst_char + 1) == 'E')
		validate_texture(line, params, 2);
	else if (*(line + fst_char) == 'E' && *(line + fst_char + 1) == 'A')
		validate_texture(line, params, 2);
	else if (*(line + fst_char) == 'S')
		validate_texture(line, params, 1);
	else if (*(line + fst_char) == 'F')
		validate_color(line, params, true);
	else if (*(line + fst_char) == 'C')
		validate_color(line, params, false);
	else
		invalid_param(line, params);
}
