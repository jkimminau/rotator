/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 19:49:33 by shomami           #+#    #+#             */
/*   Updated: 2018/03/02 01:16:41 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cpysrc;
	char	*cpydst;

	cpysrc = (char *)src;
	cpydst = (char *)dst;
	if (cpysrc < cpydst)
		while (len > 0)
		{
			len--;
			cpydst[len] = cpysrc[len];
		}
	ft_memcpy(dst, src, len);
	return (dst);
}
