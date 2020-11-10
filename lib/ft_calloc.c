/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 20:16:24 by wupdegra          #+#    #+#             */
/*   Updated: 2020/08/28 10:49:15 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lib.h>

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	ptr = (unsigned char*)malloc(num * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, size * num);
	return (ptr);
}
