/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_only.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:08:51 by wupdegra          #+#    #+#             */
/*   Updated: 2020/08/04 20:05:38 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config.h>

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
