/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 22:26:52 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/01 13:27:22 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../lib/lib.h"

typedef	struct s_config	t_config;
typedef	struct s_app	t_app;

void			ft_error(const char *error_msg);
void			init_config(t_config *params, int argc);
void			destroy_params(t_config *params);
void			destroy_parse(char *line, t_config *params);
int				get_hex_value(int red, int green, int blue);
char			**copy_char_matrix(char **matrix, int row);
void			destroy_char_matrix(char **matrix);
char			*ft_delete_ws(const char *str);
int				ft_contains_only(const char *str, char sym);
void			destroy(t_app *app, t_config *params);
void			destroy_app(t_app *app);
void			init_cub_params(t_app *app, t_config *params);
int				*init_image(int width, int height);

#endif
