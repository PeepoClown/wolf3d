/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 15:23:53 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:12:51 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int		*init_image(int width, int height)
{
	int		i;
	int		*img;

	if (!(img = (int*)malloc(sizeof(int) * (width * height))))
		return (NULL);
	i = 0;
	while (i < (width * height))
	{
		img[i] = 0;
		i++;
	}
	return (img);
}
