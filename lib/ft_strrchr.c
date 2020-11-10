/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:44:09 by wupdegra          #+#    #+#             */
/*   Updated: 2020/08/04 12:42:07 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lib.h>

char	*ft_strrchr(const char *str, int ch)
{
	char	*s;

	s = (char*)str + ft_strlen(str);
	while (s >= str)
	{
		if (*s == ch)
			return (s);
		s--;
	}
	return (NULL);
}
