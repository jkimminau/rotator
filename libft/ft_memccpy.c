/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:36:54 by shomami           #+#    #+#             */
/*   Updated: 2018/03/02 01:15:41 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cpysrc;
	unsigned char	*cpydst;
	size_t			i;

	i = 0;
	cpysrc = (unsigned char *)src;
	cpydst = (unsigned char *)dst;
	while (i < n)
	{
		cpydst[i] = cpysrc[i];
		if (cpysrc[i] == (unsigned char)c)
			return (cpydst + i + 1);
		i++;
	}
	return (NULL);
}
