/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 21:36:36 by wupdegra          #+#    #+#             */
/*   Updated: 2020/08/28 10:50:01 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lib.h>

void	*ft_memset(void *ptr, int ch, size_t len)
{
	unsigned char	*str;

	str = (unsigned char*)ptr;
	while (len--)
	{
		*str = (unsigned char)ch;
		str++;
	}
	return (ptr);
}
