/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:20:17 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/01 13:26:32 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config.h>

int			get_hex_value(int red, int green, int blue)
{
	return (pow(2, 16) * red + pow(2, 8) * green + blue);
}
