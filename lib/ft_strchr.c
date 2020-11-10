/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 15:26:33 by wupdegra          #+#    #+#             */
/*   Updated: 2020/08/04 12:41:56 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lib.h>

char	*ft_strchr(const char *str, int ch)
{
	char	*s;

	s = (char*)str;
	while (s <= str + ft_strlen(str))
	{
		if (*s == ch)
			return (s);
		s++;
	}
	return (NULL);
}
