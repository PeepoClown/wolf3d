/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:10:08 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:55:30 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config.h>

static	char	*check_texture_free(char *texture, char *trimmed_line)
{
	free(texture);
	return (trimmed_line);
}

static	void	check_texture(char *line, t_config *params, char *t_line)
{
	char	fst_char;
	char	sec_char;

	fst_char = *line;
	sec_char = *(line + 1);
	if (fst_char == 'N' && sec_char == 'O')
		params->n_texture = (!(params->n_texture)) ? ft_strdup(t_line)
							: check_texture_free(params->n_texture, t_line);
	else if (fst_char == 'S' && sec_char == 'O')
		params->s_texture = (!(params->s_texture)) ? ft_strdup(t_line)
							: check_texture_free(params->s_texture, t_line);
	else if (fst_char == 'W' && sec_char == 'E')
		params->w_texture = (!(params->w_texture)) ? ft_strdup(t_line)
							: check_texture_free(params->w_texture, t_line);
	else if (fst_char == 'E' && sec_char == 'A')
		params->e_texture = (!(params->e_texture)) ? ft_strdup(t_line)
							: check_texture_free(params->e_texture, t_line);
	else if (fst_char == 'S' && sec_char == ' ')
		params->sprite_texture = (!(params->sprite_texture)) ? ft_strdup(t_line)
							: check_texture_free(params->sprite_texture,
							t_line);
}

void			validate_texture(char *line, t_config *params, int skipped)
{
	char	*trimmed_line;
	int		fst_char;

	fst_char = 0;
	while (*(line + fst_char) == 32)
		fst_char++;
	if (*(line + fst_char + skipped) != 32)
	{
		destroy_parse(line, params);
		ft_error("Ivalid path to texture img!\n");
	}
	if (!(trimmed_line = ft_strtrim(line + fst_char + skipped, " ")))
	{
		destroy_parse(line, params);
		ft_error("Allocation error!\n");
	}
	check_texture(line + fst_char, params, trimmed_line);
	free(trimmed_line);
}
