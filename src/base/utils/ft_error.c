/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:09:04 by wupdegra          #+#    #+#             */
/*   Updated: 2020/08/04 20:06:44 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config.h>

void	ft_error(const char *error_msg)
{
	write(1, "\e[31mError\n\e[33m", 16);
	write(1, error_msg, ft_strlen(error_msg));
	write(1, "\e[39m", 5);
	exit(1);
}
