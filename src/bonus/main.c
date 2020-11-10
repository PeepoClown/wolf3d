/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 15:52:37 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:49:52 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int		main(int argc, char **argv)
{
	t_config	*params;
	t_app		*app;

	validate_args(argc, argv);
	if (!(params = (t_config*)malloc(sizeof(t_config))))
		ft_error("Allocation error!\n");
	init_config(params, argc);
	validation(argv[1], params);
	if (!(app = (t_app*)malloc(sizeof(t_app))))
	{
		destroy(app, params);
		ft_error("Allocation error!\n");
	}
	init_cub(app, params);
	if (app->save == true)
		save_screen(app);
	app->mlx.win_ptr = mlx_new_window(app->mlx.mlx_ptr, app->width,
		app->height, "cub3D");
	cub(app);
	hooks(app);
	destroy_app(app);
	return (0);
}
