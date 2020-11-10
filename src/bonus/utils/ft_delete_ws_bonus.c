/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_ws_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:08:57 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:12:43 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config_bonus.h>

char	*ft_delete_ws(const char *str)
{
	int		i;
	int		count;
	char	*res;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			count++;
		i++;
	}
	if (!(res = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			res[count++] = str[i];
		i++;
	}
	res[count] = '\0';
	return (res);
}
