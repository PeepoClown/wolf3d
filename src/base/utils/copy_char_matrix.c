/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_char_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:08:25 by wupdegra          #+#    #+#             */
/*   Updated: 2020/08/04 20:22:33 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config.h>

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
