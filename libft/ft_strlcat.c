/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:03:13 by shomami           #+#    #+#             */
/*   Updated: 2018/03/02 01:08:18 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dsize;

	dsize = ft_strlen(dst);
	if (dsize >= dstsize)
		return (dstsize + ft_strlen(src));
	ft_strncpy(dst + dsize, src, dstsize - dsize - 1);
	dst[dstsize - 1] = '\0';
	return (dsize + ft_strlen(src));
}
