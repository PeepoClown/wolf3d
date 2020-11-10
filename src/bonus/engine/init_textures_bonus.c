/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:15:57 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:17:42 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

t_orient	choose_texture_orient(int side)
{
	if (side == 0)
		return (North);
	else if (side == 1)
		return (South);
	else if (side == 2)
		return (West);
	else
		return (East);
}

int			image_loader(t_app *app, int **texture, char *path)
{
	int		x;
	int		y;
	t_img	img;

	img.img_ptr = mlx_xpm_file_to_image(app->mlx.mlx_ptr, path, &(img.width),
		&(img.height));
	if (img.img_ptr == NULL)
		return (1);
	img.data = (int*)mlx_get_data_addr(img.img_ptr, &(img.bit_per_pix),
		&(img.size_line), &(img.endian));
	if (!((*texture) = init_image(img.width, img.height)))
		return (1);
	y = 0;
	while (y < img.height)
	{
		x = 0;
		while (x < img.width)
		{
			(*texture)[img.width * y + x] = img.data[img.width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(app->mlx.mlx_ptr, img.img_ptr);
	return (0);
}

void		init_textures(t_app *app, t_config *params)
{
	if (!(app->texture = (int**)malloc(sizeof(int*) * 7)))
	{
		destroy(app, params);
		ft_error("Allocation error!\n");
	}
	app->texture[0] = NULL;
	app->texture[1] = NULL;
	app->texture[2] = NULL;
	app->texture[3] = NULL;
	app->texture[4] = NULL;
	app->texture[5] = NULL;
	app->texture[6] = NULL;
	if (image_loader(app, &(app->texture[0]), params->n_texture) == 1 ||
		image_loader(app, &(app->texture[1]), params->s_texture) == 1 ||
		image_loader(app, &(app->texture[2]), params->w_texture) == 1 ||
		image_loader(app, &(app->texture[3]), params->e_texture) == 1 ||
		image_loader(app, &(app->texture[4]), params->sprite_texture) == 1 ||
		image_loader(app, &(app->texture[5]), params->floor_texture) == 1 ||
		image_loader(app, &(app->texture[6]), params->celling_texture) == 1)
	{
		destroy(app, params);
		ft_error("Texture file can't be opened!\n");
	}
}
