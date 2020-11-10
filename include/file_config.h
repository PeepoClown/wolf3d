/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_config.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 23:02:14 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 23:47:30 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_CONFIG_H
# define FILE_CONFIG_H

# define MAX_WIDTH 1920
# define MAX_HEIGHT 1080

# include "utils.h"
# include <math.h>

typedef struct	s_resolution
{
	int		width;
	int		height;
}				t_resolution;

typedef struct	s_rgb
{
	int			red;
	int			green;
	int			blue;
	int			hex_v;
	bool		is_set;
}				t_rgb;

typedef struct	s_config
{
	int				fd;
	char			*n_texture;
	char			*s_texture;
	char			*w_texture;
	char			*e_texture;
	char			*sprite_texture;
	t_rgb			celling;
	t_rgb			floor;
	t_resolution	resolution;
	int				pos_x;
	int				pos_y;
	char			orient;
	int				map_w;
	int				map_h;
	t_list			*map;
	char			**cub_map;
	bool			map_started;
	bool			save;
}				t_config;

void			validate_args(int argc, char **argv);
void			validation(const char *filename, t_config *params);
void			validate_line(char *line, t_config *params);
void			validate_params(char *line, t_config *params);
void			validate_resolution(char *line, t_config *params);
void			validate_texture(char *line, t_config *params, int skipped);
void			validate_color(char *line, t_config *params, bool is_floor);
void			validate_map(t_config *params);
void			validate_map_line(char *line, t_config *params);
void			init_cub_map(t_config *params);
void			complete_cub_map(t_config *params);
void			check_start_position(t_config *params);
void			check_map_borders(char **map, t_config *params);
int				check_map_closed(char **map, t_config *params, int row,
									int col);

#endif
