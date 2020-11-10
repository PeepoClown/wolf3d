/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_only_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:08:51 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:12:41 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config_bonus.h>

int		ft_contains_only(const char *str, char sym)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != sym)
			return (0);
		i++;
	}
	return (1);
}
