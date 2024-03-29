/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:16:38 by wupdegra          #+#    #+#             */
/*   Updated: 2020/08/04 12:41:44 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lib.h>

bool	ft_isdigit(int ch)
{
	return (ch >= '0' && ch <= '9');
}
