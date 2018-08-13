/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 10:54:52 by shomami           #+#    #+#             */
/*   Updated: 2018/03/02 01:20:57 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cpysrc;
	char	*cpydst;
	size_t	i;

	cpysrc = (char *)src;
	cpydst = (char *)dst;
	i = 0;
	while (i < n)
	{
		cpydst[i] = cpysrc[i];
		i++;
	}
	return (dst);
}
