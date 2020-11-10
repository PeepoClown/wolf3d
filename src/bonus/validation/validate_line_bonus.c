/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:05:04 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:10:53 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config_bonus.h>

static	void	validate_line_helper(t_config *params, char *line)
{
	if (params->map_started)
	{
		destroy_parse(line, params);
		ft_error("Invalid placement of params!\n");
	}
	else
		validate_params(line, params);
}

void			validate_line(char *line, t_config *params)
{
	int		fst_char;

	if (*line == '\0' && !params->map_started)
		return ;
	else if (*line == '\0' && params->map_started)
	{
		destroy_parse(line, params);
		ft_error("Empty lines after map start!\n");
	}
	fst_char = 0;
	while (*(line + fst_char) == 32)
		fst_char++;
	if (ft_isdigit(*(line + fst_char)))
	{
		params->map_started = true;
		ft_lstadd_back(&(params->map), ft_lstnew(ft_strdup(line)));
	}
	else
		validate_line_helper(params, line);
}
