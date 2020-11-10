/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_char_matrix_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:08:25 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:12:14 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config_bonus.h>

char	**copy_char_matrix(char **matrix, int row)
{
	int		i;
	char	**res;

	if (!(res = (char**)malloc(sizeof(char*) * (row + 1))))
		return (NULL);
	i = 0;
	while (i < row)
	{
		res[i] = ft_strdup(matrix[i]);
		if (!res[i])
			return (NULL);
		i++;
	}
	res[i] = NULL;
	return (res);
}
