/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_resolution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:10:00 by wupdegra          #+#    #+#             */
/*   Updated: 2020/08/04 20:04:27 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config.h>

void	validate_resolution(char *line, t_config *params)
{
	int		fst_char;

	fst_char = 0;
	while (*(line + fst_char) == 32)
		fst_char++;
	fst_char++;
	params->resolution.width = ft_atoi(line + fst_char);
	if (params->resolution.width > MAX_WIDTH)
		params->resolution.width = MAX_WIDTH;
	while (*(line + fst_char) == 32)
		fst_char++;
	while (ft_isdigit(*(line + fst_char)))
		fst_char++;
	params->resolution.height = ft_atoi(line + fst_char);
	if (params->resolution.height > MAX_HEIGHT)
		params->resolution.height = MAX_HEIGHT;
	if (params->resolution.width < 1 || params->resolution.height < 1)
	{
		destroy_parse(line, params);
		ft_error("Invalid resolution!\n");
	}
}
